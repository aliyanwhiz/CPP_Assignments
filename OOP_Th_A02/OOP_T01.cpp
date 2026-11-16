#include <iostream>
using namespace std;

class Book {
protected:
    string title;
    string author;
public:
    Book(string t, string a) {
        title = t;
        author = a;
    }
    void showBook() {
        cout << title << " by " << author << endl;
    }
};

class EBook : public Book {
    double fileSize;
public:
    EBook(string t, string a, double size) : Book(t, a) {
        fileSize = size;
    }
    void download() {
        cout << fileSize << " MB\n";
    }
};

int main() {
    EBook eb("C++ Programming", "Aliyan Ahmed", 15.5);
    eb.showBook();
    eb.download();
    return 0;
}