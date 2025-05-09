#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int lengthOfInt(long long n) {
    if (n == 0) return 1;
    return (int) log10(abs(n)) + 1;
}

class Person {
protected:
    string name;
    int age;
    string id;
    long long contact;

public:
    Person(string n = "John Doe", int a = 0, string i = "0000", long long c = 0000000000) {
        name = n;
        age = a;
        id = i;
        contact = c;
    }

    virtual void getdata() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        while (age < 0 || age > 130) {
            cout << "Enter valid age: ";
            cin >> age;
        }

        cout << "Enter id: ";
        cin >> id;

        cout << "Enter contact: ";
        cin >> contact;
        while (lengthOfInt(contact) != 10) {
            cout << "Contact number must be exactly 10 digits: ";
            cin >> contact;
        }
    }

    virtual void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << id << endl;
        cout << "Contact: " << contact << endl;
    }

    int calculatePayment() {
        int payment;
        cout << "Enter payment amount: ";
        cin >> payment;
        while (payment < 0) {
            cout << "Payment cannot be negative. Enter again: ";
            cin >> payment;
        }
        return payment;
    }
};

class Professor : public Person {
    string department;
    string specialization;
    int hireDate;

public:
    Professor(string d = "Computer Science", string s = "AI", int h = 0)
        : department(d), specialization(s), hireDate(h) {}

    void getdata() override {
        Person::getdata();
        cout << "Enter department: ";
        cin >> department;
        cout << "Enter specialization: ";
        cin >> specialization;
        cout << "Enter hire date: ";
        cin >> hireDate;
    }

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Department: " << department << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Hire Date: " << hireDate << endl;
    }

    string getDepartment() const { return department; }
};

class Course {
    int code;
    string title;
    int credits;
    string description;
    Professor* instructor;

public:
    Course(int c = 0, string t = "Computer Science 101", int cr = 3, string d = "Introduction to Computer Science", Professor* prof = NULL)
        : code(c), title(t), credits(cr), description(d), instructor(prof) {}

    void getData() {
        cout << "Enter course code: ";
        cin >> code;
        cout << "Enter course title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter course credits: ";
        cin >> credits;
        while (credits < 0) {
            cout << "Credits cannot be negative. Enter again: ";
            cin >> credits;
        }
        cout << "Enter course description: ";
        cin.ignore();
        getline(cin, description);
    }

    void displayDetails() const {
        cout << "Course Code: " << code << endl;
        cout << "Title: " << title << endl;
        cout << "Credits: " << credits << endl;
        cout << "Description: " << description << endl;
        if (instructor) {
            cout << "Instructor Details:\n";
            instructor->displayDetails();
        }
    }
};

class Student : public Person {
protected:
    int enrollYear;
    string program;
    float GPA;
    vector<Course*> enrolledCourses;

public:
    Student(int e = 0, string p = "Computer Science", float g = 0)
        : enrollYear(e), program(p), GPA(g) {}

    void getdata() override {
        Person::getdata();
        cout << "Enter enrollment year: ";
        cin >> enrollYear;
        cout << "Enter program: ";
        cin >> program;
        cout << "Enter GPA: ";
        cin >> GPA;
        while (GPA < 0 || GPA > 4) {
            cout << "GPA must be between 0 and 4. Enter again: ";
            cin >> GPA;
        }
    }

    void enrollInCourse(Course* course) {
        enrolledCourses.push_back(course);
    }

    void displayDetails() const override {
        Person::displayDetails();
        cout << "Enrollment Year: " << enrollYear << endl;
        cout << "Program: " << program << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Enrolled Courses:\n";
        for (size_t i = 0; i < enrolledCourses.size(); ++i) {
            enrolledCourses[i]->displayDetails();
        }
    }
};

class GraduateStudent : public Student {
    Professor* advisor;

public:
    GraduateStudent(int e = 0, string p = "Computer Science", float g = 0, Professor* adv = NULL)
        : Student(e, p, g), advisor(adv) {}

    void getdata() override {
        Student::getdata();
        if (advisor) {
            cout << "Enter advisor details:\n";
            advisor->getdata();
        }
    }

    void displayDetails() const override {
        Student::displayDetails();
        if (advisor) {
            cout << "Advisor Details:\n";
            advisor->displayDetails();
        }
    }
};

class Department {
    string name;
    string location;
    int budget;
    vector<Professor*> professors;
    vector<Course*> courses;

public:
    Department(string n = "Computer Science", string l = "Building A", int b = 100000)
        : name(n), location(l), budget(b) {}

    void addProfessor(Professor* prof) {
        professors.push_back(prof);
    }

    void addCourse(Course* course) {
        courses.push_back(course);
    }

    void displayDetails() const {
        cout << "Department Name: " << name << endl;
        cout << "Location: " << location << endl;
        cout << "Budget: " << budget << endl;
        cout << "Professors:\n";
        for (size_t i = 0; i < professors.size(); ++i) {
            professors[i]->displayDetails();
        }
        for (size_t i = 0; i < courses.size(); ++i) {
            courses[i]->displayDetails();
        }
    }

    string getName() const { return name; }

    vector<Professor*> getProfessors() const { return professors; }

    vector<Course*> getCourses() const { return courses; }
};

class University {
    string name;
    vector<Department*> departments;

public:
    University(string n = "Default University") : name(n) {}

    void addDepartment(Department* department) {
        departments.push_back(department);
    }

    void removeDepartment(string departmentName) {
        vector<int>::iterator it = remove_if(departments.begin(), departments.end(),
            [&departmentName](Department* dept) {
                return dept->getName() == departmentName;
            });
        if (it != departments.end()) {
            departments.erase(it, departments.end());
        } else {
            cout << "Department not found.\n";
        }
    }

    void displayDetails() const {
        cout << "University Name: " << name << endl;
        for (auto dept : departments) {
            dept->displayDetails();
        }
    }

    vector<Professor*> getAllProfessors() const {
        vector<Professor*> allProfessors;
        for (auto dept : departments) {
            auto profs = dept->getProfessors();
            allProfessors.insert(allProfessors.end(), profs.begin(), profs.end());
        }
        return allProfessors;
    }

    vector<Course*> getAllCourses() const {
        vector<Course*> allCourses;
        for (auto dept : departments) {
            auto courses = dept->getCourses();
            allCourses.insert(allCourses.end(), courses.begin(), courses.end());
        }
        return allCourses;
    }
};

int main() {
    Person person("John Doe", 20, "1234", 9876543210);
    Professor* professor = new Professor("Computer Science", "AI", 2020);
    Student student(2021, "Computer Science", 3.5);
    Course* course = new Course(101, "Computer Science 101", 3, "Intro to CS", professor);
    Department* department = new Department("Computer Science", "Building A", 100000);
    University university("OpenAI University");

    department->addProfessor(professor);
    department->addCourse(course);
    university.addDepartment(department);
    student.enrollInCourse(course);

    cout << "\n--- UNIVERSITY DETAILS ---\n";
    university.displayDetails();

    cout << "\n--- STUDENT DETAILS ---\n";
    student.displayDetails();

    delete professor;
    delete course;
    delete department;

    return 0;
}
