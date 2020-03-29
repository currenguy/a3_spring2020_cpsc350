#include "StackEmpty.h"
#include "GenStack.h"
#include "GenStack.cpp"

int main(int argc, char** argv)
{
  GenStack<int>* g = new GenStack<int>(7);
  for (int i = 0; i < 7; ++i)
  {
    g->push(i);
  }
  for (int i = 0; i < 7; ++i)
  {
    cout << "TOP: " << g->top() << endl;
    g->pop();
  }

  cout << g->isEmpty() << endl;
  cout << g->isFull() << endl;
  cout << g->top() << endl;
  cout << endl;
  cout << g->capacity() << endl;
  cout << g->size() << endl;
  delete g;
  return 0;
}
