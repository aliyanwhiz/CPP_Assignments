#include <iostream>
#include <string>
using namespace std;

struct Course
{
    string courseCode;
    string courseTitle;
    int creditHours;
};

int main()
{
    Course courses[4];

    for (int i = 0; i < 4; i++)
    {
        cout << "Enter details for Course " << i + 1 << ":" << endl;
        cout << "Course Code: ";
        cin >> courses[i].courseCode;
        cout << "Course Title: ";
        cin >> courses[i].courseTitle;
        cout << "Credit Hours: ";
        cin >> courses[i].creditHours;
        cout << endl;
    }

    int choice = 0;
    do
    {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Display All Courses" << endl;
        cout << "2. Search Course by Code" << endl;
        cout << "3. Display Total Credit Hours" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            cout << "--- Course List ---" << endl;
            for (int i = 0; i < 4; i++)
            {
                cout << "Code: " << courses[i].courseCode
                     << " | Title: " << courses[i].courseTitle
                     << " | Credit Hours: " << courses[i].creditHours << endl;
            }
        }
        else if (choice == 2)
        {
            string searchCode;
            cout << "Enter Course Code to Search: ";
            cin >> searchCode;

            bool found = false;
            for (int i = 0; i < 4; i++)
            {
                if (courses[i].courseCode == searchCode)
                {
                    cout << "Course Found -> Course Title: " << courses[i].courseTitle
                         << " | Credit Hours: " << courses[i].creditHours << endl;
                    found = true;
                    break; // Exit loop once found
                }
            }
            if (!found)
            {
                cout << "Course not found." << endl;
            }
        }
        else if (choice == 3)
        {
            int totalCredits = 0;
            for (int i = 0; i < 4; i++)
            {
                totalCredits += courses[i].creditHours;
            }
            cout << "Total Credit Hours: " << totalCredits << endl;
        }
        else if (choice != 4)
        {
            cout << "Invalid Choice. Please try again." << endl;
        }

    } while (choice != 4);

    cout << "Exiting system. Goodbye!" << endl;
    return 0;
}