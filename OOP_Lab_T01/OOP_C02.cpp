#include <iostream>
using namespace std;

class department{
    string name;
    int capacity;
    int count;
public:
    department(string n, int c): name(n), capacity(c), count(0) {};
};
class teacher: public department{
    string name;
    int empId;
public:
    teacher(string n, int c, string tname, int id): department(n, c), name(tname), empId(id) {
        
    };

};