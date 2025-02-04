#include <iostream>
using namespace std;
#include "Course.h"
#include "Student.h"
#include "Teacher.h"

int main()
{
    Student s1("ibrahim");
    Student s2("johar");
    Teacher t1("professor smith"); Teacher t2("professor johnson");
    Course c1("mathematics"); Course c2("physics");

    c1.addStudent(&s1); c2.addStudent(&s2);
    c1.addTeacher(&t1); c2.addTeacher(&t2);

    cout << "students enrolled in " << c1.getName() << ":\n";
    for(const auto& student : c1.getStudents())
    {
        cout << student->getName() << endl;
    }

    cout << "teachers teaching " << c1.getName() << ":\n";
    for(const auto& teacher : c1.getTeachers())
    {
        cout << teacher->getName() << endl;
    }

    cout << "students enrolled in " << c2.getName() << ":\n";
    for(const auto& student : c2.getStudents())
    {
        cout << student->getName() << endl;
    }

    cout << "teachers teaching " << c2.getName() << ":\n";
    for(const auto& teacher : c2.getTeachers())
    {
        cout << teacher->getName() << endl;
    }

    return 0;
}
