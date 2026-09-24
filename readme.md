# Richard C++ Learning Projects

A collection of C++ learning projects featuring various programming exercises and experimental projects.

## 📁 Project Structure

```
richard/
├── hello/                    # Basic Hello World exercises
├── luogu/                   # Competitive programming problems (Luogu platform)
├── queue/                   # Queue data structure implementation
├── richard-learn-c++/       # C++ language learning (Part 1)
├── richard-learn-c++-2/     # C++ language learning (Part 2)
├── richard计算器/           # Simple calculator project
├── wukong/                  # Other learning projects
└── .gitignore              # Git ignore configuration
```

## 🎯 Main Contents

### 1. **luogu/** - Competitive Programming
- Solutions to problems from Luogu platform
- Example: `B2110.cc` - Find the first character that appears only once in a string

### 2. **richard-learn-c++/** and **richard-learn-c++-2/**
- Systematic study of C++ language features
- Covers basic syntax, data structures, object-oriented programming, etc.

### 3. **queue/**
- Queue data structure implementation and applications

### 4. **richard计算器/**
- Simple calculator program implementation

### 5. **hello/**, **wukong/**
- Various learning and experimental projects

## 🛠️ Compilation and Execution

### Compile a single file
```bash
g++ -o output_name source_file.cc
g++ -o program luogu/B2110.cc
```

### Run the compiled program
```bash
./program
```

### Using clang (if installed)
```bash
clang++ -o output_name source_file.cc
```

## 📋 Requirements

- C++11 or higher
- GCC/Clang compiler
- Linux/macOS/Windows (with compiler tools configured)

## 📝 Code Style

- Uses `#include <bits/stdc++.h>` (common in competitive programming)
- `using namespace std;` for simplified code
- Clear variable naming and comments

## 🚫 .gitignore Configuration

The following files are ignored:
```
# Compiled output
*.o, *.out, *.exe, *.a, *.so, *.dylib

# IDE configuration
.vscode/, .idea/, *.swp, *~

# Build directories
build/, dist/, cmake-build-*/

# Executable files
hello, queue, wukong
```

## 📖 Learning Resources

- **Competitive Programming**: Luogu Platform
- **C++ Reference**: cppreference.com
- **Programming Contests**: Usually uses GCC compiler with `-O2` optimization

## 🔧 Common Compilation Flags

```bash
# Enable all warnings
g++ -Wall -Wextra -o program source.cc

# Optimization (common in contests)
g++ -O2 -o program source.cc

# Debug mode
g++ -g -o program source.cc

# Combined options
g++ -Wall -O2 -g -o program source.cc
```

## 💡 Quick Start

1. **Write code**: Create a `.cc` file in the corresponding directory
2. **Compile**: `g++ -o output source.cc`
3. **Test**: `./output` and input test data
4. **Submit**: Verify correctness before submission

## 📌 Important Notes

- Competitive programming typically uses Linux environment
- Pay attention to data type ranges (int, long long, float, double)
- Input/output format must match problem requirements exactly
- Clean up generated executables periodically (`.gitignore` will exclude them automatically)

---

**Created**: 2026-09-25  
**Type**: Learning Project Collection
