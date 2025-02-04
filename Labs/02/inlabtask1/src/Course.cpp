#include <iostream>
#include "Course.h"
using namespace std;

Course::Course(const string& name): name(name) {}

void Course::addStudent(Student* student) 
{
    students.push_back(student);
}

void Course::addTeacher(Teacher* teacher)
{
    teachers.push_back(teacher);
}

const string& Course::getName() const { return name; }

const vector<Student*>& Course::getStudents() const { return students; }

const vector<Teacher*>& Course::getTeachers() const { return teachers; }
