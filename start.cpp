#include <iostream>
#include <iomanip>

using namespace std;
class Person{
    string name;
    int age;
    string id;
    int contact;
    public:
    Person(){
        name="John Doe";
        age=0;
        id="0000";
        contact= 0000000000;
    }

    void getdata(){
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter age: ";
        cin>>age;
        cout<<"Enter id: ";
        cin>>id;
        cout<<"Enter contact: ";
        cin>>contact;
    }
    Person(string n,int a,string i,int c){
        name=n;
        age=a;
        id=i;
        contact=c;
    }
};

class Student{
    int enrollDate;
    string program;
    int GPA;
    public:
    Student(){
        enrollDate=0;
        program="Computer Science";
        GPA=0;
    }
    void getdata(){
        cout<<"Enter enrollment date: ";
        cin>>enrollDate;
        cout<<"Enter program: ";
        cin>>program;
        cout<<"Enter GPA: ";
        cin>>GPA;
    }
    Student(int e,string p,int g){
        enrollDate=e;
        program=p;
        GPA=g;
    }
};

class Professor{
    string department;
    string specialization;
    int hireDate;
    public:
    Professor(){
        department="Computer Science";
        specialization="AI";
        hireDate=0;
    }
    void getdata(){
        cout<<"Enter department: ";
        cin>>department;
        cout<<"Enter specialization: ";
        cin>>specialization;
        cout<<"Enter hire date: ";
        cin>>hireDate;
    }
    Professor(string d,string s,int h){
        department=d;
        specialization=s;
        hireDate=h;
    }
};

class Course{
    int code;
    string title;
    int credits;
    string description;
    public:
    Course(){
        code=0;
        title="Computer Science 101";
        credits=3;
        description="Introduction to Computer Science";
    }
    void getdata(){
        cout<<"Enter course code: ";
        cin>>code;
        cout<<"Enter course title: ";
        cin>>title;
        cout<<"Enter course credits: ";
        cin>>credits;
        cout<<"Enter course description: ";
        cin>>description;
    }
    Course(int c,string t,int cr,string d){
        code=c;
        title=t;
        credits=cr;
        description=d;
    }
};

class Department{
    string name;
    string location;
    int budget;
    public:
    Department(){
        name="Computer Science";
        location="Building A";
        budget=100000;
    }
    void getdata(){
        cout<<"Enter department name: ";
        cin>>name;
        cout<<"Enter department location: ";
        cin>>location;
        cout<<"Enter department budget: ";
        cin>>budget;
    }
    Department(string n,string l,int b){
        name=n;
        location=l;
        budget=b;
    }
};


int main(){
    Person person;
    Person person("John Doe", 20, "1234", 9876543210);

    Professor professor;
    Professor professor("Computer Science", "AI", 2020);

    Student student;
    Student student(2021, "Computer Science", 3.5);

    Course course;  
    Course course(101, "Computer Science 101", 3, "Introduction to Computer Science");

    Department department;
    Department department("Computer Science", "Building A", 100000);
    

    return 0;
}