#include <iostream>
#include "Teacher.h"
using namespace std;

Teacher::Teacher(const string& name): name(name) {}

void Teacher::teachCourse(Course* course)
{
    teachingCourses.push_back(course);
}

const string& Teacher::getName() const
{
    return name;
}

const vector<Course*>& Teacher::getTeachingCourses() const
{
    return teachingCourses;
} 