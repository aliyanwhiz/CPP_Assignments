#include <iostream>
using namespace std;

int main() {
    double x, n, poweredBase,Factorial;
    double res = 1;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter n: ";
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        // moving to new term with inital input
        poweredBase = x;
        Factorial = 1;
        for(int j = 1; j <= i; j++)
        {
            //power setting
            if(j > 1) poweredBase *= x;

            //factorial setting
            Factorial *= j;
        }

        // cout << i << " Pwr : " << poweredBase << " | Fac : " << Factorial << endl;
        res += (poweredBase/Factorial);
    }

    cout << "Result: " << res << endl;
    return 0;
}