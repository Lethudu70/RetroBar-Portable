#include <windows.h>
#include <stdio.h>
#include <shlwapi.h>

// Définition de WinMain pour masquer la console Windows
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    
    // 1. Déterminer le dossier actuel (où se trouvent le lanceur et RetroBar)
    wchar_t rootPath[MAX_PATH];
    GetModuleFileNameW(NULL, rootPath, MAX_PATH);
    PathRemoveFileSpecW(rootPath);

    // 2. Chemin vers RetroBar.exe
    wchar_t exePath[MAX_PATH];
    swprintf(exePath, MAX_PATH, L"%s\\RetroBar.exe", rootPath);

    // Vérifier si RetroBar.exe existe
    if (!PathFileExistsW(exePath)) {
        MessageBoxW(NULL, L"RetroBar.exe introuvable dans le dossier actuel.", L"Erreur", MB_ICONERROR | MB_OK);
        return 1;
    }

    // 3. Configuration des variables d'environnement locales pour le Runtime portable
    SetEnvironmentVariableW(L"DOTNET_ROOT", rootPath);
    SetEnvironmentVariableW(L"DOTNET_MULTILEVEL_LOOKUP", L"0");

    // 4. Ajouter le dossier courant au PATH de ce processus
    wchar_t oldPath[32767];
    wchar_t newPath[32767];
    GetEnvironmentVariableW(L"PATH", oldPath, 32767);
    swprintf(newPath, 32767, L"%s;%s", rootPath, oldPath);
    SetEnvironmentVariableW(L"PATH", newPath);

    // 5. Structure de configuration pour le lancement
    STARTUPINFOW si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_SHOWNORMAL; // Force l'affichage normal de RetroBar
    ZeroMemory(&pi, sizeof(pi));

    // Lancement de RetroBar avec rootPath comme répertoire de travail
    if (!CreateProcessW(
            exePath, 
            NULL, 
            NULL, 
            NULL, 
            FALSE, 
            0, 
            NULL, 
            rootPath, // Working Directory
            &si, 
            &pi
        )) 
    {
        wchar_t errorMsg[256];
        swprintf(errorMsg, 256, L"Impossible de lancer RetroBar. Code d'erreur : %lu", GetLastError());
        MessageBoxW(NULL, errorMsg, L"Erreur de lancement", MB_ICONERROR | MB_OK);
        return 1;
    }

    // 6. Attente de 2 secondes pour valider la stabilité
    Sleep(2000);

    // Vérifier si le processus s'est arrêté brusquement
    DWORD exitCode;
    if (GetExitCodeProcess(pi.hProcess, &exitCode)) {
        if (exitCode != STILL_ACTIVE) {
            wchar_t crashMsg[512];
            swprintf(crashMsg, 512, L"RetroBar a crashé immédiatement après son lancement (Code de sortie: %lu).\n\nVérifie que les fichiers du runtime .NET portable (dossiers 'host' et 'shared') sont correctement placés aux côtés de l'application.", exitCode);
            MessageBoxW(NULL, crashMsg, L"Erreur d'exécution", MB_ICONERROR | MB_OK);
        }
    }

    // Fermeture des handles devenus inutiles
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    
    return 0;
}