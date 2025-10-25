# Codeforces Practice Repository

Welcome! This repository serves as a personal log of my C++ solutions for problems on the Codeforces platform.

The main purpose of this repo is to:
* Track my progress and improvement over time.
* Maintain an organized archive of problems I've solved.
* Review past solutions and data structures.

This collection is a work in progress. New solutions will be added as I continue to practice.

## 🚀 C++ Workflow Setup (VS Code)

This repository is set up for a simple and effective C++ workflow on Windows using VS Code.

### 1. Prerequisites

Before you begin, ensure you have:
* **A C++ Compiler:** This setup uses `g++` from the **MinGW-w64** toolchain.
* **VS Code Extensions:** The **C/C++ Extension Pack** from Microsoft installed in VS Code.

### 2. Configuration

The `.vscode` folder in this repository contains two key files:
* `c_cpp_properties.json`: Configures the C/C++ extension (IntelliSense) to find the compiler and header files.
* `tasks.json`: Creates a default build task for compiling the active file.

### 3. How to Build and Run

This workflow is a simple two-step process:

1.  **Build (Compile):**
    * Open any `.cpp` file.
    * Press **`Ctrl+Shift+B`**.
    * This runs the build task, which compiles your code and creates a `.exe` file with the same name (e.g., `test.cpp` becomes `test.exe`).

2.  **Run:**
    * In the VS Code integrated terminal, type the name of your new executable.
    * Example: `.\test.exe`
    * The program's output will appear directly in the terminal.