#include "SyntaxChecker.h"

//This is the implementation for the Syntax Checker

//Default constructor
SyntaxChecker::SyntaxChecker()
{
  m_delimiters = new GenStack<char>();
  m_lines = new GenStack<int>();
}

//Destructor
SyntaxChecker::~SyntaxChecker()
{
  delete m_delimiters;
  delete m_lines;
}

//Reads in a file and checks delimiter balance
//Returns false if (), [], or {} are unbalanced
//Outputs an error with line number of any unbalance
bool SyntaxChecker::readFile(string file)
{
  ifstream inFS;
  string input = "y";
  string line = "";
  int lineNumber = 0;

  //Continues to loop while the user wants to continue
  while (tolower(input[0]) == 'y')
  {
    m_delimiters->clear();
    m_lines->clear();
    lineNumber = 0;
    inFS.open(file);

    //Checks if the input file is open before proceeding
    if (inFS.is_open())
    {
      //Iterates through the input file
      while (!inFS.eof())
      {
        lineNumber++;
        //Gets a line from the file
        getline(inFS, line);
        //Makes sure there are no error state flags set off
        if (!inFS.fail())
        {
          //Iterates through each character in the line
          for (int i = 0; i < line.size(); ++i)
          {
            //Pushes opening delimiters to the stack
            //Pushes the line number of the file to another stack
            if (line[i] == '(' || line[i] == '[' || line[i] == '{')
            {
              m_delimiters->push(line[i]);
              m_lines->push(lineNumber);
            }

            //Cases for closing delimiters
            else if (line[i] == ')' || line[i] == ']' || line[i] == '}')
            {
              //Provides an error if a closing delimiter appears first
              if (m_delimiters->isEmpty())
              {
                cout << "\n\n\n\n\nERROR: Unexpected " << line[i];
                cout << " on Line " << lineNumber << endl << endl << endl;
                return false;
              }
              //Cases for mismatched delimiters
              else
              {
                if (m_delimiters->top() == '(' && line[i] != ')')
                {
                  cout << "\n\n\n\n\nERROR: Expecting a ) on Line " << lineNumber << endl;
                  cout << "\tto match ( on Line " << m_lines->top() << "." << endl;
                  cout << "\tFound a " << line[i] << " instead." << endl << endl << endl;
                  return false;
                }
                else if (m_delimiters->top() == '[' && line[i] != ']')
                {
                  cout << "\n\n\n\n\nERROR: Expecting a ] on Line " << lineNumber << endl;
                  cout << "\tto match [ on Line " << m_lines->top() << "." << endl;
                  cout << "\tFound a " << line[i] << " instead." << endl << endl << endl;
                  return false;
                }
                else if (m_delimiters->top() == '{' && line[i] != '}')
                {
                  cout << "\n\n\n\n\nERROR: Expecting a } on Line " << lineNumber << endl;
                  cout << "\tto match { on Line " << m_lines->top() << "." << endl;
                  cout << "\tFound a " << line[i] << " instead." << endl << endl << endl;
                  return false;
                }
                //Pops the last opening delimiter if it finds the closing delimiter
                m_delimiters->pop();
                m_lines->pop();
              }
            }
          }
        }
      }
      //All opening delimiter have a match, or no delimiters exist
      if (m_delimiters->isEmpty())
      {
        cout << "\n\n\n\n\nNo errors found" << endl << endl << endl;
      }
      //Outputs an error for the last added opening delimiter without its match
      else
      {
        if (m_delimiters->top() == '(')
        {
          cout << "\n\n\n\n\nERROR: Expecting a ) on Line "  << lineNumber << endl;
          cout << "\tto match ( on Line " << m_lines->top() << "." << endl << endl << endl;
        }
        else if (m_delimiters->top() == '[')
        {
          cout << "\n\n\n\n\nERROR: Expecting a ] on Line "  << lineNumber << endl;
          cout << "\tto match [ on Line " << m_lines->top() << "." << endl << endl << endl;
        }
        else if (m_delimiters->top() == '{')
        {
          cout << "\n\n\n\n\nERROR: Expecting a } on Line "  << lineNumber << endl;
          cout << "\tto match { on Line " << m_lines->top() << "." << endl << endl << endl;
        }
      }
    }
    //Error handling for non-existent file
    else
    {
      cout << "File not found" << endl;
    }
    inFS.close();
    //Ask the user if they want to enter another file
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
