#include "SyntaxChecker.h"

SyntaxChecker::SyntaxChecker()
{
  m_delimiters = new GenStack<char>();
}

SyntaxChecker::~SyntaxChecker()
{
  delete m_delimiters;
}

void SyntaxChecker::readFile(string file)
{
  ifstream inFS;
  string input = "y";
  string line = "";
  int lineNumber = 0;
  bool foundError = false;

  while (tolower(input[0]) == 'y')
  {
    m_delimiters->clear();
    lineNumber = 0;
    inFS.open(file);
    foundError = false;


    if (inFS.is_open())
    {
      while (!inFS.eof() && foundError == false)
      {
        lineNumber++;
        getline(inFS, line);
        if (!inFS.fail())
        {
          for (int i = 0; i < line.size(); ++i)
          {
            if (line[i] == '(' || line[i] == '[' || line[i] == '{')
            {
              m_delimiters->push(line[i]);
            }
            else
            {
              if (!m_delimiters->isEmpty() && m_delimiters->top() == '(')
              {
                if (line[i] != ')' && (line[i] == ']' || line[i] == '}'))
                {
                  cout << "\n\n\n\n\nERROR Line " << lineNumber;
                  cout << ": Expecting a " << "\")\"\n\n" << endl;
                  foundError = true;
                }
                else if (line[i] == ')')
                {
                  m_delimiters->pop();
                }
              }
              else if (!m_delimiters->isEmpty() && m_delimiters->top() == '[')
              {
                if (line[i] != ']' && (line[i] == ')' || line[i] == '}'))
                {
                  cout << "\n\n\n\n\nERROR Line " << lineNumber;
                  cout << ": Expecting a " << "\"]\"\n\n" << endl;
                  foundError = true;
                }
                else if (line[i] == ']')
                {
                  m_delimiters->pop();
                }
              }
              else if (!m_delimiters->isEmpty() && m_delimiters->top() == '{')
              {
                if (line[i] != '}' && (line[i] == ')' || line[i] == ']'))
                {
                  cout << "\n\n\n\n\nERROR Line " << lineNumber;
                  cout << ": Expecting a " << "\"}\"\n\n" << endl;
                  foundError = true;
                }
                else if (line[i] == '}')
                {
                  m_delimiters->pop();
                }
              }
            }
          }
        }
      }
      if (foundError == false && !m_delimiters->isEmpty())
      {
        foundError = true;
        cout << "\n\n\n\n\nERROR Line " << lineNumber;
        if (m_delimiters->top() == '(')
        {
          cout << ": Expecting a " << "\")\"\n\n" << endl;
        }
        else if (m_delimiters->top() == '[')
        {
          cout << ": Expecting a " << "\"]\"\n\n" << endl;
        }
        else if (m_delimiters->top() == '{')
        {
          cout << ": Expecting a " << "\"}\"\n\n" << endl;
        }
      }

      // cout << endl;
      // cout << foundError << endl;
      if (foundError == false)
      {
        cout << "\n\n\n\n\nNo errors found" << endl;
      }
      //m_delimiters->print();
    }
    else
    {
      cout << "File not found" << endl;
    }
    inFS.close();
    cout << "Enter another file? [y/n] : ";
    cin >> input;
    while (tolower(input[0]) != 'y' && tolower(input[0]) != 'n')
    {
      cout << "Invalid response. Enter another file? [y/n] : ";
      cin >> input;
    }
    if (tolower(input[0]) == 'y')
    {
      cout << "File name : ";
      cin >> file;
      cout << endl;
    }
  }
}
