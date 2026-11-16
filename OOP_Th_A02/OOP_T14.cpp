#include <iostream>
using namespace std;

class InvalidCGPA {};
class InvalidAttendance {};

class ScholarshipStudent {
    string name;
    double cgpa;
    double attendance;
public:
    ScholarshipStudent(string n, double c, double a) {
        name = n;
        cgpa = c;
        attendance = a;
    }
    void checkEligibility() {
        if (cgpa < 3.0) throw InvalidCGPA();
        if (attendance < 75.0) throw InvalidAttendance();
        cout << "Scholarship Approved!\n";
    }
};

int main() {
    ScholarshipStudent student("Aliyan Ahmed", 3.4, 65.0);
    try {
        student.checkEligibility();
    } catch (InvalidCGPA) {
        cout << "Error: CGPA must be at least 3.0!\n";
    } catch (InvalidAttendance) {
        cout << "Error: Attendance must be at least 75%!\n";
    }
    return 0;
}