#include <iostream>
using namespace std;

bool contains(long long num1, int dig)
{
    while (num1 >= 10)
    {
        if ((num1 % 100) == dig)
        {
            return true;
        }
        num1 /= 10;
    }
    return false;
}

int main()
{
    int bigNum, smallNum;

    cout << "Enter large number : ";
    cin >> bigNum;
    cout << "Enter 2 Digits number : ";
    cin >> smallNum;

    // Test cases from your prompt
    cout << (contains(bigNum, smallNum) ? "True" : "False") << endl;

    return 0;
}