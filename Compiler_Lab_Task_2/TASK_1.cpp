#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<cctype>

using namespace std;

int isKeyword(char buffer[])
{
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
    "do","double","else","enum","extern","float","for","goto","if","int","long","register",
    "return","short","signed","sizeof","static","struct","switch","typedef","union",
    "unsigned","void","volatile","while"};

    int i, flag = 0;

    for(i = 0; i < 32; ++i)
    {
        if(strcmp(keywords[i], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }

    return flag;
}

bool isIdentifierValid(const char* buffer, bool isAssignment)
 {
    if(isdigit(buffer[0]) && !isAssignment)
    {
        return false;
    }

    if (isdigit(buffer[0]) && isalpha(buffer[1]))
    {
        return false;
    }

    for(int k = 0; k < strlen(buffer); k++)
    {
        if(!isalnum(buffer[k]) && buffer[k] != '_')
        {
            return false;
        }
    }

    return true;
}

int main()
 {
    char ch, buffer[15], operators[] = "+-*/%=";
    ifstream fin("program.txt");
    int i, j=0;
    bool isAssignment = false;

    if(!fin.is_open())
    {
        cout<<"error while opening the file\n";
        exit(0);
    }

    while(!fin.eof())
    {
        ch = fin.get();

        if(ch == '/')
        {
            if(fin.peek() == '/')
            {
                while(ch != '\n')
                 {
                    ch = fin.get();
                }
            }
        }

        for(i = 0; i < 6; ++i)
        {
            if(ch == operators[i])
            {
                cout<<ch<<" is operator\n";
                if (ch == '=')
                {
                    isAssignment = true;
                }
            }
        }

        if(isalnum(ch) || ch == '_')
        {
            buffer[j++] = ch;
        }
        else if((ch == ' ' || ch == '\n' || !isalnum(ch)) && (j != 0))
         {
            buffer[j] = '\0';
            j = 0;

            if(isKeyword(buffer) == 1)
            {
                cout<<buffer<<" is keyword\n";
            }
            else
            {
                bool validIdentifier = isIdentifierValid(buffer, isAssignment);
                if(validIdentifier)
                {
                    cout<<buffer<<" is identifier\n";
                }
                else
                {
                    cout<<buffer<<" is invalid identifier\n";
                }
            }

            isAssignment = false;
        }
    }

    fin.close();

    return 0;
}

