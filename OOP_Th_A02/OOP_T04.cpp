#include <iostream>
using namespace std;

class Course {
protected:
    string code;
    string title;
public:
    Course(string c, string t) {
        code = c;
        title = t;
    }
    void showCourse() {
        cout << code << " " << title << endl;
    }
};

class ProgrammingCourse : public Course {
    int labDuration;
public:
    ProgrammingCourse(string c, string t, int dur) : Course(c, t) {
        labDuration = dur;
    }
    void showLabInfo() {
        cout << labDuration << endl;
    }
};

int main() {
    ProgrammingCourse pc("CS101", "Object Oriented Programming", 3);
    pc.showCourse();
    pc.showLabInfo();
    return 0;
}