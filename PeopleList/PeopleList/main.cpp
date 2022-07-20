//
//  main.cpp
//  Business
//
//  Created by Austin Bennett on 7/7/22.
//

#include <iostream>
#include <vector>

#include "person.cpp"
#include "laborer.cpp"
#include "manager.cpp"
#include "owner.cpp"

using namespace std;

vector<Person *> list;

void DisplayAddMenu()
{
    int choice;
    do
    {
        cout << endl
             << " 1 - Add Laborer\n"
             << " 2 - Add Manager\n"
             << " 3 - Add Owner\n"
             << " 4 - Return to Main Menu\n"
             << " Enter your choice and press return: ";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            cout << "Name: ";
            string name;
            cin.ignore();
            getline(cin, name);

            cout << "Birthday: ";
            string birthday;
            getline(cin, birthday);

            cout << "SSN: ";
            string ssn;
            getline(cin, ssn);

            cout << "Job: ";
            string job;
            getline(cin, job);

            cout << "Employee ID: ";

            string laborerEmployeeID;
            getline(cin, laborerEmployeeID);

            cout << "Hourly Salary: ";
            string hourlySalary;
            getline(cin, hourlySalary);

            cout << "Hours Worked: ";
            string hoursWorked;
            getline(cin, hoursWorked);

            list.push_back(new Laborer(name, birthday, ssn, job, laborerEmployeeID, hourlySalary, hoursWorked));
        }
        else if (choice == 2)
        {
            cout << "Name: ";
            string name;
            cin.ignore();
            getline(cin, name);

            cout << "Birthday: ";
            string birthday;
            getline(cin, birthday);

            cout << "SSN: ";
            string ssn;
            getline(cin, ssn);

            cout << "Department: ";
            string department;
            getline(cin, department);

            cout << "Employee ID: ";
            string managerEmployeeID;
            getline(cin, managerEmployeeID);

            cout << "Salary: ";
            string salary;
            getline(cin, salary);

            list.push_back(new Manager(name, birthday, ssn, department, managerEmployeeID, salary));
        }
        else if (choice == 3)
        {
            cout << "Name: ";
            string name;
            cin.ignore();
            getline(cin, name);

            cout << "Birthday: ";
            string birthday;
            getline(cin, birthday);

            cout << "SSN: ";
            string ssn;
            getline(cin, ssn);

            cout << "Percent Owned: ";
            string percentOwned;
            getline(cin, percentOwned);

            cout << "Owner Since: ";
            string ownerSince;
            getline(cin, ownerSince);

            list.push_back(new Owner(name, birthday, ssn, percentOwned, ownerSince));
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid Input\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (choice != 4);
}

void DisplayListMenu()
{
    int choice;
    do
    {
        cout << endl
             << " 1 - View Laborers\n"
             << " 2 - View Managers\n"
             << " 3 - View Owners\n"
             << " 4 - Return to Main Menu\n"
             << " Enter your choice and press return: ";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            for (int i = 0; i < list.size(); i++)
            {
                string type = list[i]->getType();
                if (type == "Laborer")
                {
                    list[i]->Display();
                }
            }
        }
        else if (choice == 2)
        {
            for (int i = 0; i < list.size(); i++)
            {
                string type = list[i]->getType();
                if (type == "Manager")
                {
                    list[i]->Display();
                }
            }
        }
        if (choice == 3)
        {
            for (int i = 0; i < list.size(); i++)
            {
                string type = list[i]->getType();
                if (type == "Owner")
                {
                    list[i]->Display();
                }
            }
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(10000, '\n');
        }

    } while (choice != 4);
}

int main()
{

    int choice;
    do
    {
        cout << endl
             << " 1 - Add Person\n"
             << " 2 - Display List\n"
             << " 3 - Sort List\n"
             << " 4 - Exit.\n"
             << " Enter your choice and press return: ";
        cin >> choice;
        cout << endl;

        if (choice == 1)
        {
            DisplayAddMenu();
        }
        else if (choice == 2)
        {
            DisplayListMenu();
        }
        else if (choice == 3)
        {
            int i, j, n;
            n = list.size();
            for (i = 0; i < n - 1; i++)
            {
                for (j = 0; j < n - i - 1; j++)
                {
                    if (list[j] -> getName() > list[j + 1] -> getName())
                    {
                        swap(list[j], list[j + 1]);
                    }
                }
                    
            }
            
            for (int i = 0; i < n; i++)
            {
                list[i] -> Display();
            }
                
        }
        else if (choice == 4)
        {
            cout << "End of Program.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else
        {
            cout << "Not a Valid Choice. \nChoose again.\n";
        }
    } while (choice != 4);

    return 0;
}
