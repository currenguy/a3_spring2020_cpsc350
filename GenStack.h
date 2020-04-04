#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include "StackEmpty.h"
using namespace std;

template <typename E>
class GenStack
{
  public:
    //Default constructor
    GenStack();
    //Overloaded constructor to declare max size
    GenStack(int capacity);
    //Destructor
    ~GenStack();

    //Core Functions

    //Pushes an element onto the top
    void push(const E& e);
    //Pops the top element (doesn't return it)
    void pop() throw(StackEmpty);

    //Helper Functions

    //Returns the max capacity of the stack
    int capacity() const;
    //Returns the number of elements in the stack
    int size() const;
    //Returns true if the stack is empty
    bool isEmpty() const;
    //Returns true if the stack is full
    bool isFull() const;
    //Returns the top element
    const E& top() const throw(StackEmpty);
    //Prints the stack information
    void print();
    //Resets the top index to create an empty stack
    void clear();

  private:
    //Max size of the stack
    int m_capacity;
    //Top index of the stack
    int m_top;
    //Array of elements used for the stack
    E* m_array;
};

#endif

//Implementation

//Default constructor
template <typename E>
GenStack<E>::GenStack()
{
  m_capacity = 100;
  m_top = -1;
  m_array = new E[m_capacity];
}

//Overloaded constructor to declare max size
template <typename E>
GenStack<E>::GenStack(int capacity)
{
  m_capacity = capacity;
  m_top = -1;
  m_array = new E[m_capacity];
}

//Destructor
template <typename E>
GenStack<E>::~GenStack()
{
  delete this->m_array;
}

//Pushes an element onto the top
template <typename E>
void GenStack<E>::push(const E& e)
{
  if (!this->isFull())
  {
    this->m_array[++m_top] = e;
  }
  else
  {
    m_capacity += 10;
    E* tempArray = new E[m_capacity];
    for (int i = 0; i < this->size(); ++i)
    {
      tempArray[i] = m_array[i];
    }

    m_array = tempArray;
    this->m_array[++m_top] = e;
    tempArray = NULL;
    delete tempArray;

  }
}

//Pops the top element (doesn't return it)
template <typename E>
void GenStack<E>::pop() throw(StackEmpty)
{

  if (!this->isEmpty())
  {
    --m_top;
  }
  else
  {
    throw StackEmpty();
  }
}

//Returns the max capacity of the stack
template <typename E>
int GenStack<E>::capacity() const
{
  return m_capacity;
}

//Returns the number of elements in the stack
template <typename E>
int GenStack<E>::size() const
{
  return m_top + 1;
}

//Returns true if the stack is empty
template <typename E>
bool GenStack<E>::isEmpty() const
{
  return (m_top == -1);
}

//Returns true if the stack is full
template <typename E>
bool GenStack<E>::isFull() const
{
  return (m_top == m_capacity - 1);
}

//Returns the top element
template <typename E>
const E& GenStack<E>::top() const throw(StackEmpty)
{
  if (!this->isEmpty())
  {
    return this->m_array[m_top];
  }
  else
  {
    throw StackEmpty();
  }
}

//Prints the stack information
template <typename E>
void GenStack<E>::print()
{
  cout << endl << "PRINTED STACK (Capacity: " << this->m_capacity;
  cout << ", Number of elements: " << this->size() << ")" << endl << endl;

  cout << "\tTOP: [ ";
  for (int i = this->m_top; i >= 0; --i)
  {
    if (i == 0)
    {
      cout << m_array[i];
    }
    else
    {
      cout << m_array[i] << ", ";
    }
  }
  cout << " ] :BOTTOM" << endl << endl;
}

//Resets the top index to create an empty stack
template <typename E>
void GenStack<E>::clear()
{
  this->m_top = -1;
}
