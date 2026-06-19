#include <iostream>
#include <string>
using namespace std;

struct Mobile {
    string brand;
    string model;
    double price;
};

int main() {
    Mobile inventory[5];

    for (int i = 0; i < 5; i++) {
        cout << "Enter details for Mobile " << i + 1 << ":" << endl;
        cout << "Brand Name: ";
        cin >> inventory[i].brand;
        cout << "Model: ";
        cin >> inventory[i].model;
        cout << "Price: ";
        cin >> inventory[i].price;
        cout << endl;
    }

    cout << "--- Complete Mobile List ---" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". Brand: " << inventory[i].brand 
             << " | Model: " << inventory[i].model 
             << " | Price: " << inventory[i].price << endl;
    }
    cout << endl;

    int expensiveIndex = 0;
    for (int i = 1; i < 5; i++) {
        if (inventory[i].price > inventory[expensiveIndex].price) {
            expensiveIndex = i;
        }
    }

    cout << "Most Expensive Mobile: Brand: " << inventory[expensiveIndex].brand 
         << " Model: " << inventory[expensiveIndex].model 
         << " Price: " << inventory[expensiveIndex].price << endl;

    return 0;
}