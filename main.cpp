#include "StackEmpty.h"
#include "SyntaxChecker.h"

int main(int argc, char** argv)
{
  SyntaxChecker* sc = new SyntaxChecker();

  if (argc < 2)
  {
    cout << "No file provided." << endl;
    return 1;
  }

  string file = argv[1];
  sc->readFile(file);

  delete sc;

  return 0;
}
