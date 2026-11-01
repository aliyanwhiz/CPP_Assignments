#include <iostream>
using namespace std;

class Course{
public:
    string title;
    Course(string t): title(t) {};
};

class Teacher{
    Course *course;
public:
    Teacher(Course *c): course(c) {};
    void showCourse(){
        cout << course->title << endl;
    };

};

int main(){
    Teacher t(new Course("OOP"));
    t.showCourse();

    return 0;

}