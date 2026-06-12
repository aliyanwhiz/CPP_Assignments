#include <iostream>
using namespace std;

int main() {
    int i = 0;
    while (i < 10) {
        if(i % 2 == 0) continue;
        if(i == 7) break;
        
        cout << i << " " << endl;
        i++;
    }
    return 0;
}