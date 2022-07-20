#include <string>
#include <iostream>

#pragma once

using namespace std;

class Person
{
protected:
    string _name;
    string _birthday;
    string _ssn;

public:
    Person(string name, string birthday, string ssn)
    {
        _name = name;
        _birthday = birthday;
        _ssn = ssn;
    }

    // Accessors
    
    string getBirthday() { return _birthday; };
    string getSSN() { return _ssn; };

    // Mutators
    void setName(string name) { _name = name; }
    void setBirthday(string birthday) { _birthday = birthday; };
    void setSSN(string ssn) { _ssn = ssn; };

    virtual void Display() = 0;
    virtual string getType() = 0;
    virtual string getName() = 0;
};
