#include <iostream>
using namespace std;

class Device {
protected:
    string brand;
public:
    Device() {
        brand = "Dawlance";
    }
    void operate() {
        cout << brand << endl;
    }
};

class SmartAC : public Device {
    int temperature;
public:
    SmartAC() : Device() {
        temperature = 22;
    }
    void setTemperature(int temp) {
        temperature = temp;
        cout << temperature << endl;
    }
};

int main() {
    SmartAC ac;
    ac.operate();
    ac.setTemperature(24);
    return 0;
}