#include <memory>
#include <iostream>
#include <string>
#include <map>
#include "University_Types.h"

using namespace std;

Student::Student(const std::string &n) : name(n), id(max_id++) {}

Student::~Student()
{

    //check that department.expired() returns false
    //this means that department.lock() will give a
    //valid shared pointer
    //if it department.expired() returned true it would result in an empty 
    //shared pointer
    //BASICALLY IF EXPIRED RETURNS TRUE IT MEANS THE ASSOCIATED
    //SHARED POINTER NO LONGER EXISTS
    // AS A RESULT WHEN TRYING TO ACCESS IT THROUGH department.lock()
    // WE GET A SEGMENTATION FAULT
    if (!department.expired()) 
    {
        // here we obtain the associated shared pointer from
        //weak pointer and deregister student from 
        //this department based on id
        department.lock()->deregisterStudent(id); 
    }
    cout << "Student " << name << " destroyed." << endl;
}

void Student::setDepartment(const shared_ptr<Department> new_dept)
{
    // if the department no longer exists
    //we want to deregister the student from this department
    if (!department.expired())
    {
        department.lock()->deregisterStudent(id);
    }
    //otherwise point weak pointer to the shared department pointer 
    department = new_dept;
}

int Student::getId() const
{
    return id;
}

int Student::max_id = 0;

Department::Department(const std::string &n) : name(n) {}

Department::~Department()
{
    cout << "Department " << name << " destroyed." << endl;
}

void Department::deregisterStudent(const int id)
{
    //In C++17 onwards we can define a variable inside an "if" condition!
    //This variable is usable inside the code block of the if statement.
    if(auto it = students.find(id); it != students.end())
    {
        students.erase(it);
    }
}

void Department::addStudent(const shared_ptr<Student> new_student)
{
    students[new_student->getId()] = new_student;
}