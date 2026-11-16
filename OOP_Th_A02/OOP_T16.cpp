#include <iostream>
using namespace std;

class RoomUnavailable {
public:
    RoomUnavailable() {}
    void showMessage() const {
        cout << "Error: The requested room is already occupied!\n";
    }
};

int main() {
    string studentName = "Aliyan Ahmed";
    bool isOccupied = true;
    try {
        if (isOccupied) {
            throw RoomUnavailable();
        }
    } catch (RoomUnavailable e) {
        e.showMessage();
    }
    return 0;
}