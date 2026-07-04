#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cctype>

using namespace std;

bool isDelimiter(char ch)
{
    return (ch == ' ' || ch == ',' || ch == ';' || ch == '.');
}

bool isInteger(const string& str)
{
    for (char ch : str)
    {
        if (!isdigit(ch))
        {
            return false;
        }
    }
    return true;
}

bool isRealNumber(const string& str)
{
    bool foundPeriod = false;
    for (char ch : str)
    {
        if (ch == '.')
        {
            if (foundPeriod)
            {
                return false;
            }
            foundPeriod = true;
        }
        else if (!isdigit(ch))
        {
            return false;
        }
    }
    return foundPeriod;
}

int main()
{
    ifstream fin("program.txt");
    char ch;
    string token;

    if (!fin.is_open())
    {
        cout << "Error while opening the file\n";
        exit(0);
    }

    while (fin.get(ch))
    {
        if (isDelimiter(ch))
        {
            if (!token.empty())
            {
                if (isInteger(token))
                {
                    cout << "Integer: " << token << endl;
                }
             else if (isRealNumber(token))
             {
                    cout << "Real number: " << token << endl;
             }
                token.clear();
            }
            cout << "Delimiter: " << ch << endl;
        }
    else if (isdigit(ch) || ch == '.')
        {
            token += ch;
        }
    else if (isalpha(ch))
    {
            if (!token.empty())
             {
                if (isInteger(token))
                {
                    cout << "Integer: " << token << endl;
                }
                else if (isRealNumber(token))
               {
                    cout << "Real number: " << token << endl;
                }
                token.clear();
            }

            while (fin.get(ch) && isalpha(ch)){}
            fin.unget();
        }
    }


    if (!token.empty())
    {
        if (isInteger(token))
        {
            cout << "Integer: " << token << endl;
        }
        else if (isRealNumber(token))
        {
            cout << "Real number: " << token << endl;
        }
    }

    fin.close();
    return 0;
}

