#include <iostream>

using namespace std;

class Teacher{
public:
    void teach()
    {

        cout << "Teaching students" << endl;
    }
};

class Researcher{
public:
    void research()
    {

        cout << "Conducting research" << endl;
    }
};

class Professor : public Teacher, public Researcher{
public:
    void work()
    {

        cout << "Professor is working" << endl;
    }
};

int main(){

    Professor p;
    p.teach();
    p.research();
    p.work();

    return 0;
}