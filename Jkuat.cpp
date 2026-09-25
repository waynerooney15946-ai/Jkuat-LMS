#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

/*
=========================================================
 JKUAT UNIVERSITY INFORMATION SYSTEM
 C++ CONSOLE PROTOTYPE

 Modules:
 1. Student Module
 2. Lecturer Module
 3. Admin Module
 4. LMS
 5. Student Portal
 6. File-based Database

 =========================================================
*/

/* =====================================================
   DATA STRUCTURES
   ===================================================== */

struct Student {
    string id;
    string name;
    string password;
    string programme;
    string year;
    string semester;
};

struct Lecturer {
    string id;
    string name;
    string password;
};

struct Unit {
    string code;
    string name;
    string lecturerID;
};

struct Registration {
    string studentID;
    string unitCode;
    string semester;
};

struct Mark {
    string studentID;
    string unitCode;
    double assignment;
    double cat;
    double exam;
};

struct Content {
    string unitCode;
    string type;
    string title;
    string description;
};


/* =====================================================
   GLOBAL DATA
   ===================================================== */

vector<Student> students;
vector<Lecturer> lecturers;
vector<Unit> units;
vector<Registration> registrations;
vector<Mark> marks;
vector<Content> contents;


/* =====================================================
   UTILITY FUNCTIONS
   ===================================================== */

void pauseScreen() {
    cout << "\nPress ENTER to continue...";
    cin.ignore();
    cin.get();
}

void clearScreen() {
    // Portable alternative
    for (int i = 0; i < 30; i++)
        cout << "\n";
}

vector<string> split(string line, char delimiter) {
    vector<string> result;
    string item;
    stringstream ss(line);

    while (getline(ss, item, delimiter)) {
        result.push_back(item);
    }

    return result;
}


/* =====================================================
   FILE DATABASE
   ===================================================== */

void saveStudents() {
    ofstream file("students.txt");

    for (auto &s : students) {
        file << s.id << "|"
             << s.name << "|"
             << s.password << "|"
             << s.programme << "|"
             << s.year << "|"
             << s.semester << "\n";
    }

    file.close();
}

void loadStudents() {
    students.clear();

    ifstream file("students.txt");

    if (!file)
        return;

    string line;

    while (getline(file, line)) {
        vector<string> data = split(line, '|');

        if (data.size() >= 6) {
            Student s;

            s.id = data[0];
            s.name = data[1];
            s.password = data[2];
            s.programme = data[3];
            s.year = data[4];
            s.semester = data[5];

            students.push_back(s);
        }
    }

    file.close();
}


void saveLecturers() {
    ofstream file("lecturers.txt");

    for (auto &l : lecturers) {
        file << l.id << "|"
             << l.name << "|"
             << l.password << "\n";
    }

    file.close();
}

void loadLecturers() {
    lecturers.clear();

    ifstream file("lecturers.txt");

    if (!file)
        return;

    string line;

    while (getline(file, line)) {
        vector<string> data = split(line, '|');

        if (data.size() >= 3) {
            Lecturer l;

            l.id = data[0];
            l.name = data[1];
            l.password = data[2];

            lecturers.push_back(l);
        }
    }

    file.close();
}


void saveUnits() {
    ofstream file("units.txt");

    for (auto &u : units) {
        file << u.code << "|"
             << u.name << "|"
             << u.lecturerID << "\n";
    }

    file.close();
}

void loadUnits() {
    units.clear();

    ifstream file("units.txt");

    if (!file)
        return;

    string line;

    while (getline(file, line)) {

        vector<string> data = split(line, '|');

        if (data.size() >= 3) {

            Unit u;

            u.code = data[0];
            u.name = data[1];
            u.lecturerID = data[2];

            units.push_back(u);
        }
    }

    file.close();
}


void saveRegistrations() {

    ofstream file("registrations.txt");

    for (auto &r : registrations) {

        file << r.studentID << "|"
             << r.unitCode << "|"
             << r.semester << "\n";
    }

    file.close();
}


void loadRegistrations() {

    registrations.clear();

    ifstream file("registrations.txt");

    if (!file)
        return;

    string line;

    while (getline(file, line)) {

        vector<string> data = split(line, '|');

        if (data.size() >= 3) {

            Registration r;

            r.studentID = data[0];
            r.unitCode = data[1];
            r.semester = data[2];

            registrations.push_back(r);
        }
    }

    file.close();
}


void saveMarks() {

    ofstream file("marks.txt");

    for (auto &m : marks) {

        file << m.studentID << "|"
             << m.unitCode << "|"
             << m.assignment << "|"
             << m.cat << "|"
             << m.exam << "\n";
    }

    file.close();
}


void loadMarks() {

    marks.clear();

    ifstream file("marks.txt");

    if (!file)
        return;

    string line;

    while (getline(file, line)) {

        vector<string> data = split(line, '|');

        if (data.size() >= 5) {

            Mark m;

            m.studentID = data[0];
            m.unitCode = data[1];
            m.assignment = stod(data[2]);
            m.cat = stod(data[3]);
            m.exam = stod(data[4]);

            marks.push_back(m);
        }
    }

    file.close();
}


void saveContents() {

    ofstream file("contents.txt");

    for (auto &c : contents) {

        file << c.unitCode << "|"
             << c.type << "|"
             << c.title << "|"
             << c.description << "\n";
    }

    file.close();
}


void loadContents() {

    contents.clear();

    ifstream file("contents.txt");

    if (!file)
        return;

    string line;

    while (getline(file, line)) {

        vector<string> data = split(line, '|');

        if (data.size() >= 4) {

            Content c;

            c.unitCode = data[0];
            c.type = data[1];
            c.title = data[2];
            c.description = data[3];

            contents.push_back(c);
        }
    }

    file.close();
}


void loadAllData() {

    loadStudents();
    loadLecturers();
    loadUnits();
    loadRegistrations();
    loadMarks();
    loadContents();
}


void saveAllData() {

    saveStudents();
    saveLecturers();
    saveUnits();
    saveRegistrations();
    saveMarks();
    saveContents();
}


/* =====================================================
   SEARCH FUNCTIONS
   ===================================================== */

Student* findStudent(string id) {

    for (auto &s : students) {

        if (s.id == id)
            return &s;
    }

    return nullptr;
}


Lecturer* findLecturer(string id) {

    for (auto &l : lecturers) {

        if (l.id == id)
            return &l;
    }

    return nullptr;
}


Unit* findUnit(string code) {

    for (auto &u : units) {

        if (u.code == code)
            return &u;
    }

    return nullptr;
}


/* =====================================================
   GRADE CALCULATION
   ===================================================== */

double calculateTotal(Mark m) {

    return m.assignment + m.cat + m.exam;
}


string calculateGrade(double total) {

    if (total >= 70)
        return "A";

    if (total >= 60)
        return "B";

    if (total >= 50)
        return "C";

    if (total >= 40)
        return "D";

    return "F";
}


/* =====================================================
   STUDENT REGISTRATION
   ===================================================== */

bool isRegistered(string studentID, string unitCode) {

    for (auto &r : registrations) {

        if (r.studentID == studentID &&
            r.unitCode == unitCode) {

            return true;
        }
    }

    return false;
}


void registerUnit(Student &student) {

    clearScreen();

    cout << "========================================\n";
    cout << "        UNIT REGISTRATION\n";
    cout << "========================================\n";

    cout << "\nAvailable Units:\n\n";

    for (auto &u : units) {

        cout << u.code << " - "
             << u.name << "\n";
    }

    string code;

    cout << "\nEnter unit code: ";
    cin >> code;

    Unit* unit = findUnit(code);

    if (unit == nullptr) {

        cout << "\nUnit does not exist.\n";
        pauseScreen();
        return;
    }

    if (isRegistered(student.id, code)) {

        cout << "\nYou are already registered for this unit.\n";
        pauseScreen();
        return;
    }

    Registration r;

    r.studentID = student.id;
    r.unitCode = code;
    r.semester = student.semester;

    registrations.push_back(r);

    saveRegistrations();

    cout << "\nUnit registered successfully.\n";

    pauseScreen();
}


/* =====================================================
   STUDENT VIEW REGISTERED UNITS
   ===================================================== */

void viewRegisteredUnits(Student &student) {

    clearScreen();

    cout << "========================================\n";
    cout << "       REGISTERED UNITS\n";
    cout << "========================================\n\n";

    bool found = false;

    for (auto &r : registrations) {

        if (r.studentID == student.id) {

            Unit* unit = findUnit(r.unitCode);

            if (unit != nullptr) {

                cout << unit->code
                     << " - "
                     << unit->name
                     << "\n";

                found = true;
            }
        }
    }

    if (!found)
        cout << "No registered units found.\n";

    pauseScreen();
}


/* =====================================================
   STUDENT VIEW MARKS
   ===================================================== */

void viewStudentMarks(Student &student) {

    clearScreen();

    cout << "========================================\n";
    cout << "          MY GRADES\n";
    cout << "========================================\n\n";

    cout << left
         << setw(12) << "UNIT"
         << setw(15) << "ASSIGNMENT"
         << setw(10) << "CAT"
         << setw(10) << "EXAM"
         << setw(10) << "TOTAL"
         << setw(10) << "GRADE"
         << "\n";

    cout << string(67, '-') << "\n";

    bool found = false;

    for (auto &m : marks) {

        if (m.studentID == student.id) {

            double total = calculateTotal(m);

            cout << left
                 << setw(12) << m.unitCode
                 << setw(15) << m.assignment
                 << setw(10) << m.cat
                 << setw(10) << m.exam
                 << setw(10) << total
                 << setw(10) << calculateGrade(total)
                 << "\n";

            found = true;
        }
    }

    if (!found)
        cout << "\nNo marks available yet.\n";

    pauseScreen();
}


/* =====================================================
   STUDENT VIEW LMS CONTENT
   ===================================================== */

void viewLMSContent(Student &student) {

    clearScreen();

    cout << "========================================\n";
    cout << "            LMS CONTENT\n";
    cout << "========================================\n\n";

    for (auto &r : registrations) {

        if (r.studentID == student.id) {

            for (auto &c : contents) {

                if (c.unitCode == r.unitCode) {

                    cout << "[" << c.type << "] "
                         << c.unitCode << "\n";

                    cout << "Title: "
                         << c.title << "\n";

                    cout << "Details: "
                         << c.description << "\n\n";
                }
            }
        }
    }

    pauseScreen();
}


/* =====================================================
   STUDENT PORTAL
   ===================================================== */

void studentPortal(Student &student) {

    int choice;

    do {

        clearScreen();

        cout << "========================================\n";
        cout << "       JKUAT STUDENT PORTAL\n";
        cout << "========================================\n";

        cout << "\nWelcome, " << student.name << "\n";

        cout << "\n1. View Profile";
        cout << "\n2. Register Unit";
        cout << "\n3. View Registered Units";
        cout << "\n4. View LMS Content";
        cout << "\n5. View Grades";
        cout << "\n6. Logout";

        cout << "\n\nSelect option: ";
        cin >> choice;

        switch (choice) {

        case 1:

            clearScreen();

            cout << "Student ID: "
                 << student.id << "\n";

            cout << "Name: "
                 << student.name << "\n";

            cout << "Programme: "
                 << student.programme << "\
