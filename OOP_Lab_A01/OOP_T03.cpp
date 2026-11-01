#include <iostream>
using namespace std;

class SwiftRide
{
protected:
    double baseFare;

public:
    SwiftRide(double f) { baseFare = f; }

    virtual void calculateFare(double distance) { cout << "Base Fare: " << baseFare * distance << endl; }
};

class BikeRide : public SwiftRide
{
public:
    BikeRide(double f) : SwiftRide(f) {}

    void calculateFare(double distance) { cout << "Bike Fare: " << baseFare * distance * 0.8 << endl; }
};

class CarRide : public SwiftRide
{
public:
    CarRide(double f) : SwiftRide(f) {}

    void calculateFare(double distance) { cout << "Car Fare: " << baseFare * distance * 1.5 << endl; }
};

int main()
{
    BikeRide b(50);
    CarRide c(50);

    b.calculateFare(10);
    c.calculateFare(10);
    return 0;
}