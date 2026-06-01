# RetroBar Portable Wrapper

## Original Software Ownership

RetroBar is developed by **Sam Johnson and community contributors**.  
This project does NOT claim any ownership over RetroBar or its source code.

RetroBar is licensed under the Apache License 2.0.

---

## Overview

This project is a **portable packaging and launcher wrapper for RetroBar**, allowing the application to be executed directly from a self-contained directory without a traditional installation process.

It is designed for:
- Virtual machines
- Windows Sandbox
- Portable USB usage
- Testing and development environments

---

## What This Project Does

This project does NOT modify RetroBar’s source code.

Instead, it provides a portability layer that:
- Bundles the original RetroBar application
- Includes a custom native launcher (`launcher.exe`)
- Allows execution from a self-contained folder
- Simplifies startup in isolated environments

In short:
👉 This project repackages a standard desktop application into a portable execution environment.

---

## How It Works

The launcher:
1. Detects its current directory
2. Checks for `RetroBar.exe`
3. Configures local environment variables (when applicable)
4. Launches RetroBar using a native Windows process
5. Provides basic error handling and validation

No system-wide installation is required.

---

## Original Software

This package includes **RetroBar**, developed by Sam Johnson and community contributors.

RetroBar is licensed under the:

### Apache License 2.0
http://www.apache.org/licenses/LICENSE-2.0

All original copyright notices remain intact.

---

## Included Third-Party Dependencies

This package also includes:

### gong-wpf-dragdrop
Licensed under the BSD 3-Clause License

Copyright (c) Jan Karger, Steven Kirk and Contributors

This library is included as part of RetroBar’s dependencies and remains under its original license terms.

Owner: https://github.com/dremin/

---

## Licenses Summary

This project contains multiple licensing components:

### 1. RetroBar
- License: Apache License 2.0

### 2. gong-wpf-dragdrop
- License: BSD 3-Clause License

### 3. This Wrapper / Launcher
- Custom code created for portability
- No restrictions beyond included dependencies
- Distributed as part of this packaging

---

## Requirements and how to use it

- Windows 10 / 11
- .NET Desktop Runtime (depending on whether you use the portable or non-portable version)
- No installation required (portable mode)

- To run the portable version, launch `RetroBar_portable.exe`.
- To run the normal version, launch `RetroBar.exe`. In this case, you need .NET Desktop Runtime 6 or higher installed on the computer.

The .NET Desktop Runtime is usually installed automatically if missing. If you need a specific version, you can download it here:

.NET 6: https://dotnet.microsoft.com/fr-fr/download/dotnet/6.0  
.NET 7: https://dotnet.microsoft.com/fr-fr/download/dotnet/7.0  
.NET 8: https://dotnet.microsoft.com/fr-fr/download/dotnet/8.0  
.NET 9: https://dotnet.microsoft.com/fr-fr/download/dotnet/9.0  
.NET 10: https://dotnet.microsoft.com/fr-fr/download/dotnet/10.0  

---

## Important Notes

- This is NOT an official RetroBar release.
- This is a third-party portable wrapper and packaging.
- The original RetroBar application remains unchanged.
- No ownership of RetroBar or its dependencies is claimed.

---

## Legal Compliance

This project fully respects:
- Apache License 2.0 (RetroBar)
- BSD 3-Clause License (dependencies)

All required license files and copyright notices are preserved in this repository/package.

---

## Purpose

This project was created for:
- Portable execution of desktop applications
- Virtual machine and sandbox testing
- Development and debugging environments
- Experimentation with portable application packaging

---

## Disclaimer

This software is provided "AS IS", without warranty of any kind.
Use at your own risk.
