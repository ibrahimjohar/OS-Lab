#include <iostream>
#include "Student.h"
using namespace std;

Student::Student(const string& name): name(name) {}

void Student::enrollCourse(Course* course)
{
    enrolledCourses.push_back(course);
}

const string& Student::getName() const { return name; }

const vector<Course*>& Student::getEnrolledCourses() const { return enrolledCourses; }


