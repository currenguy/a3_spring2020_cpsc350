#ifndef SYNTAXCHECKER_H
#define SYNTAXCHECKER_H

#include <iostream>
#include <fstream>
#include "GenStack.h"
using namespace std;

//This is the header for the Syntax Checker

class SyntaxChecker
{
  public:
    //Default constructor
    SyntaxChecker();
    //Destructor
    ~SyntaxChecker();

    //Reads in a file and checks delimiter balance
    //Returns true if all (), [], and {} are balanced
    bool readFile(string file);

  private:
    //Stores opening delimiters
    GenStack<char>* m_delimiters;
    //Stores the line numbers of opening delimiters
    GenStack<int>* m_lines;
};

#endif
