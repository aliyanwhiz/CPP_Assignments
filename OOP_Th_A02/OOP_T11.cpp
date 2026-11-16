#include <iostream>
using namespace std;

void checkTemperature(int x) {
    if (x == 1) throw 100;
    if (x == 0) throw 'T';
    if (x == -1) throw 2.5;
}

int main() {
    int values[] = {1, 0, -1};
    for (int i = 0; i < 3; i++) {
        try {
            checkTemperature(values[i]);
        } catch (int) {
            cout << "Integer exception\n";
        } catch (char c) {
            cout << "Character exception: " << c << endl;
        } catch (double d) {
            cout << "Double exception: " << d << endl;
        }
    }
    return 0;
}