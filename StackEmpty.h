#ifndef STACKEMPTY_H
#define STACKEMPTY_H

#include <iostream>
#include <exception>
using namespace std;

class StackEmpty : public exception
{
  public:
    virtual const char* what() const throw()
    {
      return "ERROR: Trying to access top element from empty stack.";
    }
    //StackEmpty(const string& err) : g{}
};

#endif
