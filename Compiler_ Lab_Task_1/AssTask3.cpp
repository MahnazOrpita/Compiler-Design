#include <iostream>
#include <string>
using namespace std;

bool isIdentifier(const string& input) {
    if (input.empty() || !isalpha(input[0]) && input[0] != '_')
        return false;

    for (char c : input.substr(1)) {
        if (!isalnum(c) && c != '_')
            return false;
    }

    return true;
}

int main() {
    string input;
    cout << "Enter input: ";
    cin >> input;

    bool validIdentifier = isIdentifier(input);

    cout << "The string \"" << input << "\" is " << (validIdentifier ? "a valid identifier." : "not a valid identifier. It should start with an alphabet character or underscore, followed by alphanumeric characters or underscores.") << "\n";

    return 0;
}

