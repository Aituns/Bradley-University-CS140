#include "person.cpp"

using namespace std;

class Laborer : public Person
{
protected:
    string _job;
    string _laborerEmployeeID;
    string _hourlySalary;
    string _hoursWorked;

public:
    Laborer(string laborerName, string laborerBirthday, string laborerSSN, string job, string employeeID, string hourlySalary, string hoursWorked) : Person(laborerName, laborerBirthday, laborerSSN)
    {
        _job = job;
        _laborerEmployeeID = employeeID;
        _hourlySalary = hourlySalary;
        _hoursWorked = hoursWorked;
    }

    // Accessors
    string getJob() { return _job; };
    string getEmployeeID() { return _laborerEmployeeID; };
    string getHourlySalary() { return _hourlySalary; };
    string getHoursWorked() { return _hoursWorked; };
    string getType() { return "Laborer"; }
    virtual string getName() { return _name; };

    // Mutators
    void setJob(string job) { _job = job; };
    void setEmployeeID(string employeeID) { _laborerEmployeeID = employeeID; };
    void setHourlySalary(string hourlySalary) { _hourlySalary = hourlySalary; };
    void setHoursWorked(string hoursWorked) { _hoursWorked = hoursWorked; };

    void Display()
    {
        cout << endl;
        cout << getType() << ":" << endl;
        cout << "   " << getName() << " " << getBirthday() << " " << getSSN() << " " << getJob() << " " << getEmployeeID() << " " << getHourlySalary() << " " << getHoursWorked() << endl;
    }
};
