#include "StackEmpty.h"
#include "GenStack.h"
#include "GenStack.cpp"

int main(int argc, char** argv)
{
  GenStack<int>* g = new GenStack<int>(3);
  while (g->size() < g->capacity())
  {
    g->push(4);
  }

  cout << g->capacity() << endl;
  cout << g->size() << endl;

  for (int i = 0; i < 8; ++i)
  {
    g->push(i);
  }

  cout << g->capacity() << endl;
  cout << g->size() << endl;

  while (g->size() > 0)
  {
    cout << "TOP: " << g->top() << endl;
    g->pop();
  }
  
  cout << g->isEmpty() << endl;
  cout << g->isFull() << endl;
  cout << endl;
  cout << g->capacity() << endl;
  cout << g->size() << endl;
  delete g;
  return 0;
}
