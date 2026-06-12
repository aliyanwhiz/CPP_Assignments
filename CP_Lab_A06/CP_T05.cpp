#include <iostream>
#include <string>
using namespace std;

int main() {
    string username;
    int password;

    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;

    if (username == "admin" && password == 1234)
        cout << "✔ Login Successful" << endl;
    else
        cout << "Login Failed" << endl;

    return 0;
}