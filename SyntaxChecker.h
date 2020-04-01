#ifndef SYNTAXCHECKER_H
#define SYNTAXCHECKER_H

#include <iostream>
#include <fstream>
#include "GenStack.h"
#include "GenStack.cpp"
using namespace std;

class SyntaxChecker
{
  public:
    SyntaxChecker();
    ~SyntaxChecker();
    bool readFile(string file);
  private:
    GenStack<char>* m_delimiters; //Stores opening delimiters
    GenStack<int>* m_lines; //Stores the lines of opening delimiters
};

#endif
