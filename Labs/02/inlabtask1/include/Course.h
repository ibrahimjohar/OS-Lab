#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

#include "Student.h"
#include "Teacher.h"

using namespace std;

class Student;
class Teacher;

class Course
{
    private:
        string name;
        vector<Student*> students;
        vector<Teacher*> teachers;
    public:
        Course(const string& name);
        void addStudent(Student* student);
        void addTeacher(Teacher* teacher);
        const string& getName() const;
        const vector<Student*>& getStudents() const;
        const vector<Teacher*>& getTeachers() const;
};

#endif
