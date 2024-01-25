#include <memory>
#include <iostream>
#include <string>
#include "University_Types.h"

using namespace std;


int main()
{
    // declare a department 
    shared_ptr<Department> physics = make_shared<Department>("Physics and Astronomy");
    shared_ptr<Department> maths = make_shared<Department>("Mathematics and Statistics");

    // declare a student
    shared_ptr<Student> Alice = make_shared<Student>("Alice");
    shared_ptr<Student> Bob = make_shared<Student>("Bob");

    // set student's department
    Alice->setDepartment(physics);

    // add student to department list
    physics->addStudent(Alice);

    return 0;
}