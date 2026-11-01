#include <iostream>
#include <string>
using namespace std;

class Product {
    int code;
    string name;
    double price;
    int stock;
public:
    Product(int c, string n, double p, int s) {
        code = c;
        name = n;
        price = p;
        stock = s;
    }
    
    int getCode() { return code; }
    string getName() { return name; }
    double getPrice() { return price; }
    int getStock() { return stock; }
    
    void setPrice(double p) { price = p; }
    
    bool sell(int qty) {
        if (qty <= stock) {
            stock -= qty;
            return true;
        }
        cout << "Out of stock!\n";
        return false;
    }
    
    void show() {
        cout << code << " " << name << " Rs." << price << " Stock:" << stock << endl;
    }
};

class Customer {
    int id;
    string name;
public:
    Customer(int i, string n) {
        id = i;
        name = n;
    }
    string getName() { return name; }
    void show() { cout << "Customer: " << name << endl; }
};

class OrderItem {
    Product* p;
    int qty;
    double priceAtBuy;
public:
    OrderItem(Product* product = nullptr, int q = 0) {
        p = product;
        qty = q;
        priceAtBuy = (p != nullptr) ? p->getPrice() : 0;
    }
    
    double getSubTotal() {
        return priceAtBuy * qty;
    }
    
    void show() {
        if (p != nullptr) {
            cout << p->getName() << " x " << qty << " = Rs." << getSubTotal() << endl;
        }
    }
};

class Order {
    Customer* cust;
    OrderItem items[5];
    int count;
public:
    Order(Customer* c) {
        cust = c;
        count = 0;
    }
    
    void addItem(Product* p, int qty) {
        if (count < 5 && p->sell(qty)) {
            items[count] = OrderItem(p, qty);
            count++;
        }
    }
    
    double getTotal() {
        double sum = 0;
        for (int i = 0; i < count; i++) {
            sum += items[i].getSubTotal();
        }
        return sum;
    }
    
    void showOrder() {
        cout << "--- Order Details ---\n";
        cust->show();
        for (int i = 0; i < count; i++) {
            items[i].show();
        }
        cout << "Total Bill: Rs." << getTotal() << "\n---------------------\n";
    }
};

int main() {
    Product p1(1, "Shirt", 2000, 10);
    Product p2(2, "Jeans", 3500, 5);
    
    Customer c1(1, "Ali");
    
    Order o(&c1);
    o.addItem(&p1, 2);
    o.addItem(&p2, 1);
    
    o.showOrder();
    
    p1.setPrice(2500);
    cout << "After price change:\n";
    o.showOrder();
    
    return 0;
}