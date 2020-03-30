#include "GenStack.h"

template <typename E>
GenStack<E>::GenStack()
{
  m_capacity = 100;
  m_top = -1;
  m_array = new E[m_capacity];
}

template <typename E>
GenStack<E>::GenStack(int capacity)
{
  m_capacity = capacity;
  m_top = -1;
  m_array = new E[m_capacity];
}

template <typename E>
GenStack<E>::~GenStack()
{
  delete this->m_array;
}

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

    for (int i = 0; i < this->size(); ++i)
    {
      cout << tempArray[i] << endl;
    }
    m_array = tempArray;
    this->m_array[++m_top] = e;
    tempArray = NULL;
    delete tempArray;
  }
}

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

template <typename E>
int GenStack<E>::capacity() const
{
  return m_capacity;
}

template <typename E>
int GenStack<E>::size() const
{
  return m_top + 1;
}

template <typename E>
bool GenStack<E>::isEmpty() const
{
  return (m_top == -1);
}

template <typename E>
bool GenStack<E>::isFull() const
{
  return (m_top == m_capacity - 1);
}

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
