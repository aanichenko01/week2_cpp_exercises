#include <memory>
#include <map>
#include <string>

using namespace std;

class Department;

class Student
{
    public:
    Student(const std::string &n);

    ~Student();

    void setDepartment(const shared_ptr<Department> new_dept);

    int getId() const;

    private:
    // Static variable means same value shared by every object in class
    // This allows us to create a unique id for each student by increasing
    // each time
    static int max_id;
    
    string name;
    int id;
    weak_ptr<Department> department;
};

class Department
{
    public:
    Department(const std::string &n);

    ~Department();

    void deregisterStudent(const int id);

    void addStudent(const shared_ptr<Student> new_student);

    private:
    string name;
    map<int, weak_ptr<Student>> students;
};