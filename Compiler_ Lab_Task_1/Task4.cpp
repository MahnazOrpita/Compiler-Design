#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cout << "Source file couldn't be opened";
        return -1;
    }

    char ch;
    int vowel = 0, consonant = 0;

    while (file.get(ch)) {
        cout << ch;
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U') {
                vowel++;
                cout << "(" << ch << ") ";
            } else {
                consonant++;
                cout << ch << " ";
            }
        }
    }

    file.close();

    cout << "\n\nNumber of vowels = " << vowel << "\nNumber of consonants = " << consonant << endl;

    return 0;
}


