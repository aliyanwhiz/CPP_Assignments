#include <iostream>
using namespace std;

class Product {
    double price;
public:
    Product(double p) { price = p; }
    friend void printPriceTag(const Product& p);
};

void printPriceTag(const Product& p) {
    cout << "Price Tag -> Rs. " << p.price << endl;
}

int main() {
    Product prod(2500);
    printPriceTag(prod);
    return 0;
}