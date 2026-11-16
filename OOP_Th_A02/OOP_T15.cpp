#include <iostream>
using namespace std;

class MyException {};
class LowMarks : public MyException {};
class IncompleteExam : public MyException {};

class Exam {
    string name;
    int marks;
    int percentCompleted;
public:
    Exam(string n, int m, int p) {
        name = n;
        marks = m;
        percentCompleted = p;
    }
    void evaluate() {
        if (marks < 40) throw LowMarks();
        if (percentCompleted < 80) throw IncompleteExam();
        cout << "Exam Passed!\n";
    }
};

int main() {
    Exam studentExam("Aliyan Ahmed", 35, 70);
    try {
        studentExam.evaluate();
    } catch (LowMarks) {
        cout << "Low Marks!\n";
    } catch (IncompleteExam) {
        cout << "Incomplete Examination!\n";
    }
    return 0;
}