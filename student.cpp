#include <iostream>
#include <fstream>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;

public:
    void addStudent() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void displayStudent() {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
        cout << "------------------------" << endl;
    }

    int getRollNo() {
        return rollNo;
    }

    void saveToFile() {
        ofstream file("students.txt", ios::app);
        file << rollNo << " " << name << " " << marks << endl;
        file.close();
    }

    bool readFromFile() {
        ifstream file("students.txt");
        if (!file)
            return false;

        while (file >> rollNo >> name >> marks) {
            displayStudent();
        }

        file.close();
        return true;
    }

    void searchStudent(int r) {
        ifstream file("students.txt");
        bool found = false;

        while (file >> rollNo >> name >> marks) {
            if (rollNo == r) {
                displayStudent();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student not found!" << endl;
        }

        file.close();
    }
};

int main() {
    Student s;
    int choice, roll;

    do {
        cout << "\n--- Student Record Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            s.addStudent();
            s.saveToFile();
            cout << "Student record saved successfully.\n";
            break;

        case 2:
            if (!s.readFromFile()) {
                cout << "No records found!\n";
            }
            break;

        case 3:
            cout << "Enter Roll Number to search: ";
            cin >> roll;
            s.searchStudent(roll);
            break;

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}