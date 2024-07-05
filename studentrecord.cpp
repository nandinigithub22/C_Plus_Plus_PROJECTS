#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    int id;
    string name;
    int age;

    Student(int id, string name, int age) {
        this->id = id;
        this->name = name;
        this->age = age;
    }

    void display() {
        cout << "ID : " << id << ", Name : " << name << ", Age : " << age << endl;
    }
};

class StudentRecordSystem {
private:
    vector<Student> students;

public:
    void addStudent(int id, string name, int age) {
        Student newStudent(id, name, age);
        students.push_back(newStudent);
        cout << "Student added successfully!" << endl;
    }

    void deleteStudent(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                cout << "Student deleted successfully!" << endl;
                return;
            }
        }
        cout << "Student not found!! " << endl;
    }

    void displayStudents() {
        if (students.empty()) {
            cout << "No students found!! " << endl;
        } else {
            for (const auto &student : students) {
                student.display();
            }
        }
    }
};

int main() {
    StudentRecordSystem srs;
    int choice, id, age;
    string name;

    while (true) {
        cout << "\nHere's Student Record System\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Display Students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID : ";
                cin >> id;
                cout << "Enter Name : ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Age : ";
                cin >> age;
                srs.addStudent(id, name, age);
                break;
            case 2:
                cout << "Enter ID : ";
                cin >> id;
                srs.deleteStudent(id);
                break;
            case 3:
                srs.displayStudents();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid Demand! Please try again." << endl;
        }
    }

    return 0;
}
