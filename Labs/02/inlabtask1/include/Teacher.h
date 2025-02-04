#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include <vector>
using namespace std;

#include "Course.h"

class Course;

class Teacher
{
    private:   
        string name;
        vector<Course*> teachingCourses;
    public:
        Teacher(const string& name);
        void teachCourse(Course* course);
        const string& getName() const;
        const vector<Course*>& getTeachingCourses() const;
};

#endif
