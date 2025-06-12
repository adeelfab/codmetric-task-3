#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Student {
    string name;
    int rollNo;
    char grade;
};


vector<Student> students;


void addStudent() {
    Student s;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Enter roll number: ";
    cin >> s.rollNo;

    cout << "Enter grade: ";
    cin >> s.grade;

    students.push_back(s);
    cout << "Student added successfully!\n";
}


void displayStudents() {
    if (students.empty()) {
        cout << "No student records found.\n";
        return;
    }

    cout << "\n--- Student Records ---\n";
    for (const auto& s : students) {
        cout << "Name: " << s.name
             << ", Roll No: " << s.rollNo
             << ", Grade: " << s.grade << endl;
    }
}


void deleteStudent() {
    int roll;
    cout << "Enter roll number to delete: ";
    cin >> roll;

    bool found = false;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->rollNo == roll) {
            students.erase(it);
            cout << "Student deleted successfully.\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with roll number " << roll << " not found.\n";
    }
}


void saveToFile() {
    ofstream file("students.txt");
    if (!file) {
        cout << "Error opening file for writing.\n";
        return;
    }

    for (const auto& s : students) {
        file << s.name << "," << s.rollNo << "," << s.grade << endl;
    }

    file.close();
    cout << "Records saved to file successfully.\n";
}


void loadFromFile() {
    ifstream file("students.txt");
    if (!file) {
        cout << "No saved file found.\n";
        return;
    }

    students.clear();
    string name;
    int roll;
    char grade;
    string line;

    while (getline(file, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.rfind(',');

        if (pos1 == string::npos || pos2 == string::npos || pos1 == pos2)
            continue;

        name = line.substr(0, pos1);
        roll = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
        grade = line[pos2 + 1];

        students.push_back({name, roll, grade});
    }

    file.close();
    cout << "Records loaded from file successfully.\n";
}


int main() {
    int choice;

    loadFromFile(); // Automatically load records at start

    do {
        cout << "\n----- Student Record Management -----\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Delete Student\n";
        cout << "4. Save Records to File\n";
        cout << "5. Load Records from File\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: deleteStudent(); break;
            case 4: saveToFile(); break;
            case 5: loadFromFile(); break;
            case 6: cout << "Exiting... Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
