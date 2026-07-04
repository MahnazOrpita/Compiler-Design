#include <iostream>
#include <string>
using namespace std;

bool isNumericConstant(const string& input) {
    for (char ch : input) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    cout << "Enter input: ";
    cin >> input;

    if (isNumericConstant(input)) {
        cout << "Numeric constant\n";
    } else {
        cout << "Not a numeric constant\n";
    }

    return 0;
}


