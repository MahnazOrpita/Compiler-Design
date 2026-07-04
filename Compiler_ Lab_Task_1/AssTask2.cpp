#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=');
}

int main() {
    string input;
    cout << "Enter input: ";
    cin >> input;

    cout << "Operators:\n";
    int operatorCount = 0;
    for (char ch : input) {
        if (isOperator(ch)) {
            operatorCount++;
            cout << "operator" << operatorCount << ": " << ch <<endl;
        }
    }

    return 0;
}

