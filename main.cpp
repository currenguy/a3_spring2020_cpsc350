#include "StackEmpty.h"
#include "GenStack.h"
#include "GenStack.cpp"
#include "SyntaxChecker.h"

int main(int argc, char** argv)
{
  // ifstream inFS;
  // ofstream outFS;
  //
  // if (argc < 2)
  // {
  //   cout << "No file provided." << endl;
  //   return 1;
  // }
  //
  // string file = argv[1];


  GenStack<char>* g = new GenStack<char>(2);
  g->print();
  g->push('a');
  g->push('b');
  g->push('c');
  g->push('d');
  g->push('e');
  g->push('f');
  g->print();

  g->push('5');
  g->print();
  g->pop();
  g->print();
  delete g;

  return 0;
}
