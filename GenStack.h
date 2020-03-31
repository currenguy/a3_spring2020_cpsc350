#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include "StackEmpty.h"
using namespace std;

template <typename E>
class GenStack
{
  public:
    GenStack(); //Default constructor
    GenStack(int capacity); //Overloaded constructor to declare max size
    ~GenStack(); //Destructor

    //Core Functions
    void push(const E& e); //Pushes an element onto the top
    void pop() throw(StackEmpty); //Pops the top element (doesn't return it)

    //Helper Functions
    int capacity() const; //Returns the max capacity of the stack
    int size() const;
    bool isEmpty() const;
    bool isFull() const;
    const E& top() const throw(StackEmpty); //Returns the top element
    void print(); //Prints the stack information
    void clear(); //Resets the top

  private:
    int m_capacity; //Max size of the stack
    int m_top; //Top index of the stack
    E* m_array; //Array of elements used for the stack

};

#endif
