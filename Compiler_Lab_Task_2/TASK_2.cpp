#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

using namespace std;

int isKeyword(char buffer[]) {
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
     "do","double","else","enum","extern","float","for","goto",
     "if","int","long","register","return","short","signed",
     "sizeof","static","struct","switch","typedef","union",
     "unsigned","void","volatile","while"};
    int i, flag = 0;

    for(i = 0; i < 32; ++i) {
        if(strcmp(keywords[i], buffer) == 0) {
            flag = 1;
            break;
        }
    }

    return flag;
}

int main() {
    char ch, buffer[15], operators[] = "+-*/%=";
    ifstream fin("program.txt");
    int i, j=0;
    bool isComment = false;

    if(!fin.is_open()) {
        cout<<"error while opening the file\n";
        exit(0);
    }

    while(!fin.eof()) {
        ch = fin.get();

        if (ch == '/' && fin.peek() == '/') {
            isComment = true;
            cout << ch;
            continue; // Skip processing '/' as an operator
        }

        for(i = 0; i < 6; ++i) {
            if(ch == operators[i]) {
                cout<<ch<<" is operator\n";
            }
        }

        if(isalnum(ch) || ch == '_') { // Allow underscores in identifiers
            buffer[j++] = ch;
        }
        else if((ch == ' ' || !isalnum(ch)) && (j != 0)) {
            buffer[j] = '\0';
            j = 0;

            if(isKeyword(buffer) == 1) {
                cout<<buffer<<" is keyword\n";
            }
            else {
                // Check if it's a valid identifier
                bool validIdentifier = true;
                if(isdigit(buffer[0])) {
                    validIdentifier = false; // Identifiers cannot start with a digit
                }
                else {
                    for(int k = 0; k < strlen(buffer); k++) {
                        if(!isalnum(buffer[k]) && buffer[k] != '_') {
                            validIdentifier = false; // Invalid character in identifier
                            break;
                        }
                    }
                }
                if(validIdentifier) {
                    cout<<buffer<<" is identifier\n";
                }
                else {
                    cout<<buffer<<" is invalid identifier\n";
                }
            }
        }

        if (isComment && ch == '\n') {
            isComment = false;
            cout << " (Comment)" << endl;
        }
    }

    fin.close();

    return 0;
}
