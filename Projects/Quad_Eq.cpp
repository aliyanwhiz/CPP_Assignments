#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, discriminant, pNumerator, nNumerator, pX, nX;
    cout << "Enter  a:";
    cin >> a;
    cout << "Enter  b:";
    cin >> b;
    cout << "Enter  c:";
    cin >> c;

    discriminant = sqrt(b * b - 4 * a * c);
    pNumerator = -b + discriminant;
    nNumerator = -b - discriminant;
    pX = pNumerator / (2 * a);
    nX = nNumerator / (2 * a);
    cout << "The roots of the quadratic equation are: " << pX << " and " << nX << endl;
    return 0;
}