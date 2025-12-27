# 25125074_25125078
Personal Finance Manager is a console-based C++ application that allows users
to manage personal financial activities, including income, expenses, recurring
transactions, and wallets.

# Build
Compile the program using a C++ compiler (C++17 or later is recommended).
# Option 1: Using Visual Studio 
The project has been pre-configured with the correct Include paths.
1. Open the solution file `25125074_25125078.sln` in Visual Studio 2022.
2. Select the **Debug** or **Release** configuration from the toolbar.
3. Press **F5** (Local Windows Debugger) to build and run the project.
*(Note: If you encounter a "header file not found" error, please verify the configuration under **Project Properties -> C/C++ -> General -> Additional Include Directories** to ensure it is set to `$(ProjectDir)include`).*
# Option 2: Using visual Code
If you prefer compiling manually via terminal or VS Code, please use the following command to correctly link the `include` directory:
**1. Compile:**
```bash
g++ -mavx2 -g src/*.cpp -Iinclude -o main.exe
```
# Run
With Visual Code:
```bash
./main.exe
```
When the program starts, the dashboard displays the current balance of all
wallets. Users can navigate through the menu to:

- Add and manage income and expense transactions
- Configure recurring monthly transactions
- Manage wallets, income sources, and expense categories
- View financial statistics by time range, wallet, or year

All changes are saved automatically, and data is preserved across sessions.

# Storage
The application uses binary file storage to save all financial data. Stored
data is automatically loaded at startup, ensuring that no information is lost
between sessions.

# Demo video link
https://youtu.be/h7kd-Vk0to8