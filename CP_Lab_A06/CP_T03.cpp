#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;
    
    char lowerCh = tolower(ch);

    if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u')
        cout << ch << " is a Vowel" << endl;
    else
        cout << ch << " is a Consonant" << endl;

    return 0;
}