#include "person.cpp"

using namespace std;

class Owner : public Person
{
protected:
    string _percentOwned;
    string _ownerSince;

public:
    Owner(string ownerName, string ownerBirthday, string ownerSSN, string percentOwned, string ownerSince) : Person(ownerName, ownerBirthday, ownerSSN)
    {
        _percentOwned = percentOwned;
        _ownerSince = ownerSince;
    }

    // Accessors
    string getPercentOwned() { return _percentOwned; };
    string getOwnerSince() { return _ownerSince; };
    string getType() { return "Owner"; };

    // Mutators
    void setPercentOwned(string percentOwned) { _percentOwned = percentOwned; };
    void setOwnerSince(string ownerSince) { _ownerSince = ownerSince; };
    
    void Display() {
        cout << endl;
        cout << getType() << ":" << endl;
        cout << "   " << getName() << " " << getBirthday() << " " << getSSN() << " " << getPercentOwned() << " " << getOwnerSince()<< endl;
    }
};
