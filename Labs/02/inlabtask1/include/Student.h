#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;

#include "Course.h"

class Course;

class Student
{
    private:
        string name;
        vector<Course*> enrolledCourses;

    public:
        Student(const string& name);
        void enrollCourse(Course* course);
        const string& getName() const;
        const vector<Course*>& getEnrolledCourses() const;
};

#endif 
