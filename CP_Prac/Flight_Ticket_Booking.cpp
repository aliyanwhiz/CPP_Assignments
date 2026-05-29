#include <iostream>

using namespace std;

const int ROWS = 12;
const int COLS = 7;

bool bookFirstClass(int Seats[][7], int rows, int cols, int noOfSeats);
bool bookBusinessClass(int Seats[][7], int rows, int cols, int noOfSeats);
bool bookEconomyClass(int Seats[][7], int rows, int cols, int noOfSeats);
int checkAvailableSeats(int Seats[][7], int rows, int cols);
void getFare();
void viewSeatingPlan(int Seats[][7], int rows, int cols);
bool systemReset(int Seats[][7], int rows, int cols);

int main() {
    int seatingPlan[ROWS][COLS] = {0};
    int choice;

    do {
        cout << "-----------------------------------------------------\n";
        cout << "Welcome to Airplane Reservation System\n";
        cout << "-----------------------------------------------------\n";
        cout << "1. Book First Class Seats\n";
        cout << "2. Book Business Class Seats\n";
        cout << "3. Book Economy Class Seats\n";
        cout << "4. View Airplane Seating Plan\n";
        cout << "5. View Fare(s)\n";
        cout << "6. System Reset\n";
        cout << "7. Exit from The Booking System\n";
        cout << "-----------------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int seatsToBook;
            cout << "Enter number of seats to book in First Class: ";
            cin >> seatsToBook;
            if (!bookFirstClass(seatingPlan, ROWS, COLS, seatsToBook)) {
                cout << "Booking failed. Not enough seats available in First Class.\n";
            } else {
                cout << "Seats booked successfully in First Class.\n";
            }
        } 
        else if (choice == 2) {
            int seatsToBook;
            cout << "Enter number of seats to book in Business Class: ";
            cin >> seatsToBook;
            if (!bookBusinessClass(seatingPlan, ROWS, COLS, seatsToBook)) {
                cout << "Booking failed. Not enough seats available in Business Class.\n";
            } else {
                cout << "Seats booked successfully in Business Class.\n";
            }
        } 
        else if (choice == 3) {
            int seatsToBook;
            cout << "Enter number of seats to book in Economy Class: ";
            cin >> seatsToBook;
            if (!bookEconomyClass(seatingPlan, ROWS, COLS, seatsToBook)) {
                cout << "Booking failed. Not enough seats available in Economy Class.\n";
            } else {
                cout << "Seats booked successfully in Economy Class.\n";
            }
        } 
        else if (choice == 4) {
            viewSeatingPlan(seatingPlan, ROWS, COLS);
        } 
        else if (choice == 5) {
            getFare();
        } 
        else if (choice == 6) {
            if (systemReset(seatingPlan, ROWS, COLS)) {
                cout << "System reset successful. All seats are now available.\n";
            }
        } 
        else if (choice == 7) {
            cout << "Exiting the system. Thank you!\n";
        } 
        else {
            cout << "Invalid choice! Please select a valid option.\n";
        }
        cout << "\n";
    } while (choice != 7);

    return 0;
}

bool bookFirstClass(int Seats[][7], int rows, int cols, int noOfSeats) {
    int available = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < cols; j++) {
            if (Seats[i][j] == 0) {
                available++;
            }
        }
    }

    if (noOfSeats > available) {
        return false;
    }

    int bookedCount = 0;
    for (int i = 0; i < 2 && bookedCount < noOfSeats; i++) {
        for (int j = 0; j < cols && bookedCount < noOfSeats; j++) {
            if (Seats[i][j] == 0) {
                Seats[i][j] = 1;
                bookedCount++;
            }
        }
    }
    return true;
}

bool bookBusinessClass(int Seats[][7], int rows, int cols, int noOfSeats) {
    int available = 0;
    for (int i = 2; i < 4; i++) {
        for (int j = 0; j < cols; j++) {
            if (Seats[i][j] == 0) {
                available++;
            }
        }
    }

    if (noOfSeats > available) {
        return false;
    }

    int bookedCount = 0;
    for (int i = 2; i < 4 && bookedCount < noOfSeats; i++) {
        for (int j = 0; j < cols && bookedCount < noOfSeats; j++) {
            if (Seats[i][j] == 0) {
                Seats[i][j] = 1;
                bookedCount++;
            }
        }
    }
    return true;
}

bool bookEconomyClass(int Seats[][7], int rows, int cols, int noOfSeats) {
    int available = 0;
    for (int i = 4; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (Seats[i][j] == 0) {
                available++;
            }
        }
    }

    if (noOfSeats > available) {
        return false;
    }

    int bookedCount = 0;
    for (int i = 4; i < rows && bookedCount < noOfSeats; i++) {
        for (int j = 0; j < cols && bookedCount < noOfSeats; j++) {
            if (Seats[i][j] == 0) {
                Seats[i][j] = 1;
                bookedCount++;
            }
        }
    }
    return true;
}

int checkAvailableSeats(int Seats[][7], int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (Seats[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}

void getFare() {
    cout << "--- Ticket Fares ---\n";
    cout << "First Class:    Rs. 18,000\n";
    cout << "Business Class: Rs. 14,000\n";
    cout << "Economy Class:  Rs. 10,000\n";
}

void viewSeatingPlan(int Seats[][7], int rows, int cols) {
    cout << "--- Airplane Seating Plan (0: Available, 1: Reserved) ---\n";
    for (int i = 0; i < rows; i++) {
        if (i == 0) cout << "[First Class]\n";
        else if (i == 2) cout << "[Business Class]\n";
        else if (i == 4) cout << "[Economy Class]\n";

        cout << "Row " << (i + 1) << (i + 1 < 10 ? "  : " : " : ");
        for (int j = 0; j < cols; j++) {
            cout << Seats[i][j] << " ";
        }
        cout << "\n";
    }
}

bool systemReset(int Seats[][7], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Seats[i][j] = 0;
        }
    }
    return true;
}