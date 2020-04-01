#include "SyntaxChecker.h"

SyntaxChecker::SyntaxChecker()
{
  m_delimiters = new GenStack<char>();
  m_lines = new GenStack<int>();
}

SyntaxChecker::~SyntaxChecker()
{
  delete m_delimiters;
  delete m_lines;
}

bool SyntaxChecker::readFile(string file)
{
  ifstream inFS;
  string input = "y";
  string line = "";
  int lineNumber = 0;
  bool foundError = false;
  char lastChar = '-';

  while (tolower(input[0]) == 'y')
  {
    m_delimiters->clear();
    m_lines->clear();
    lineNumber = 0;
    inFS.open(file);
    foundError = false;


    if (inFS.is_open())
    {
      while (!inFS.eof())
      {
        lineNumber++;
        cout << lineNumber << endl;
        getline(inFS, line);
        if (!inFS.fail())
        {
          for (int i = 0; i < line.size(); ++i)
          {



            if (i == line.size() - 1 && !m_delimiters->isEmpty())
            {
              if (m_delimiters->top() == '(' && !(line[i] == ')'))
              {
                cout << "\n\n\n\n\nERROR: Missing a ) on Line " << lineNumber << endl << endl << endl;
                return false;
              }
              else if (m_delimiters->top() == '[' && !(line[i] == ']'))
              {
                cout << "\n\n\n\n\nERROR: Missing a ] on Line " << lineNumber << endl << endl << endl;
                return false;
              }
            }




            if (line[i] == '(' || line[i] == '[' || line[i] == '{')
            {
              m_delimiters->push(line[i]);
              m_lines->push(lineNumber);
              m_delimiters->print();
              // m_lines->print();
            }

            else if (line[i] == ')' || line[i] == ']' || line[i] == '}')
            {
              if (m_delimiters->isEmpty())
              {
                cout << "\n\n\n\n\nERROR: Unexpected " << line[i] << endl;
                cout << "on Line " << lineNumber << endl << endl << endl;
                return false;
              }
              else
              {
                if (m_delimiters->top() == '(' && line[i] != ')')
                {
                  cout << "\n\n\n\n\nERROR: Expecting a ) on Line " << lineNumber << endl;
                  cout << "to match ( on Line " << m_lines->top() << endl;
                  cout << "Found a " << line[i] << " instead." << endl << endl << endl;
                  return false;
                }
                else if (m_delimiters->top() == '[' && line[i] != ']')
                {
                  cout << "\n\n\n\n\nERROR: Expecting a ] on Line " << lineNumber << endl;
                  cout << "to match ( on Line " << m_lines->top() << endl;
                  cout << "Found a " << line[i] << " instead." << endl << endl << endl;
                  return false;
                }
                else if (m_delimiters->top() == '{' && line[i] != '}')
                {
                  cout << "\n\n\n\n\nERROR: Expecting a } on Line " << lineNumber << endl;
                  cout << "to match { on Line " << m_lines->top() << endl;
                  cout << "Found a " << line[i] << " instead." << endl << endl << endl;
                  return false;
                }
                m_delimiters->pop();
                m_lines->pop();
              }
              m_delimiters->print();
              // m_lines->print();
            }
            lastChar = line[i];
          }
        }
      }

      if (m_delimiters->isEmpty())
      {
        cout << "\n\n\n\n\nNo errors found" << endl << endl << endl;
      }
      else
      {
        if (m_delimiters->top() == '(')
        {
          cout << "\n\n\n\n\nERROR: Expecting a ) on Line "  << lineNumber << endl;
          cout << "to match ( on Line " << m_lines->top() << endl;
          cout << "Found a " << lastChar << " instead." << endl << endl << endl;
        }
        else if (m_delimiters->top() == '[')
        {
          cout << "\n\n\n\n\nERROR: Expecting a ] on Line "  << lineNumber << endl;
          cout << "to match [ on Line " << m_lines->top() << endl;
          cout << "Found a " << lastChar << " instead." << endl << endl << endl;
        }
        else if (m_delimiters->top() == '{')
        {
          cout << "\n\n\n\n\nERROR: Expecting a } on Line "  << lineNumber << endl;
          cout << "to match { on Line " << m_lines->top() << endl;
          cout << "Found a " << lastChar << " instead." << endl << endl << endl;
        }
      }
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
