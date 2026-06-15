#include <iostream>
using namespace std;

void sortMarks(int* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

int main() {
    int studentMarks[10] = {14, 9, 16, 12, 13, 14, 6, 11, 18, 10};
    int arrSize = sizeof(studentMarks) / sizeof(studentMarks[0]); 


    cout << "Original marks: ";
    printArray(studentMarks, arrSize);

    sortMarks(studentMarks, arrSize);

    cout << "Sorted marks:   ";
    printArray(studentMarks, arrSize);

    return 0;
}