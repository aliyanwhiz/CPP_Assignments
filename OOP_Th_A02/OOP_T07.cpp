#include <iostream>
using namespace std;

class Locker {
    int code;
public:
    Locker(int c): code(c) {};
    friend class SecurityOfficer;
};

class SecurityOfficer {
public:
    void displayCode(const Locker& l) {
        cout << "Stored Access Code: " << l.code << endl;
    }
    void checkGuess(const Locker& l, int guess) {
        cout << "Guess " << guess << ": ";
        if (guess == l.code) cout << "Accepted\n";
        else cout << "Rejected\n";
    }
};

int main() {
    Locker locker(7539);
    SecurityOfficer officer;
    officer.displayCode(locker);
    officer.checkGuess(locker, 7539);
    officer.checkGuess(locker, 1234);
    return 0;
}