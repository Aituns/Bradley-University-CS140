#include "person.cpp"

using namespace std;

class Manager : public Person
{
protected:
    string _department;
    string _managerEmployeeID;
    string _salary;

public:
    Manager(string managerName, string managerBirthday, string managerSSN, string department, string employeeID, string salary) : Person(managerName, managerBirthday, managerSSN)
    {
        _department = department;
        _managerEmployeeID = employeeID;
        _salary = salary;
    }

    // Accessors
    string getDepartment() { return _department; };
    string getEmployeeID() { return _managerEmployeeID; };
    string getSalary() { return _salary; };
    string getType() { return "Manager"; };
    virtual string getName() { return _name; };

    // Mutators
    void setDepartment(string department) { _department = department; };
    void setEmployeeID(string employeeID) { _managerEmployeeID = employeeID; };
    void setSalary(string salary) { _salary = salary; };

    void Display()
    {
        cout << endl;
        cout << getType() << ":" << endl;
        cout << "   " << getName() << " " << getBirthday() << " " << getSSN() << " " << getDepartment() << " " << getEmployeeID() << " " << getSalary() << endl;
    }
};
