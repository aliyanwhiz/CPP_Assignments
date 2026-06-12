#include <iostream>
using namespace std;

void adjustNByGroup(int *n)
{
    if(*n % 2 == 0)
        *n += 2;
    else
        *n -= 2;
}

int main(){
    int n;
    cout << "Enter a number : ";
    cin  >> n;
    adjustNByGroup(&n);
    cout << "The number is now " << n << endl;
    return 0;
}