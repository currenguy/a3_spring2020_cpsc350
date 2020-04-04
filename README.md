# Assignment 3: Syntax Checker

## 1. IDENTIFYING INFO
- Course Number and Section: CPSC 350-01
- Assignment 3: Syntax Checker
- Full Name: Curren Taber
- Student ID: 002325149
- Chapman Email: ctaber@chapman.edu

## 2. SOURCE FILES
- README.md
- GenStack.h
- StackEmpty.h
- SyntaxChecker.h
- SyntaxChecker.cpp
- Game.cpp
- main.cpp
- Makefile
- test.txt (optional, sample input file)

## 3. DESCRIPTION
- This is a Syntax Checker
- How to use:
  - Open terminal
  - `cd` into the directory containing source files
  - Type `make all` into your command line
  - Type `./assignment3.out filename` into your command line
  - Follow the menu prompts
- Important Notes:
  - The syntax checker will store opening delimiters, then look for the first
  closing delimiter.
  - If the next closing delimiter doesn't match the last stored opening
  delimiter, then the checker will provide the line of the expected matching
  closing delimiter and the line of the specified opening delimiter.

## 4. REFERENCES
- Data Structures & Algorithms
- Rene German
- https://www.quora.com/How-does-one-write-a-custom-exception-class-in-C++
- https://www.codeproject.com/Articles/48575/How-to-Define-a-Template-Class-in-a-h-File-and-Imp
- http://www.cplusplus.com/forum/general/57229/
- https://www.geeksforgeeks.org/getline-string-c/
- http://www.cplusplus.com/reference/exception/exception/what/
