# Austin Bennett Midterm

### 1. When passing a C-style string as a parameter to a function - is the parameter passed by reference or default?

```
reference
```

### 2. When allocating the size of a C-style string, assume you want to store the string, "Hello, World!". What is the minimum size of the string you would need to allocate. Show how you would declare the string.

```
The minimum size would be 12 [11 for Hello World! and 1 for the null pointer]
```

```
char s[] = "Hello World!";
OR
char* s = "Hello World!";
```

### 3. Write a C++ program that will prompt the user for the size of a list of integers. Your program will 1. dynamically allocate an array of that size and allow the user to enter the values. 2. Your program will then go through the list and copy all even numbers to another dynamically allocated array. The functionality of 1 and 2 need to be accomplished by separate functions.

```
#include <iostream>

#include "input.h"

using namespace std;

int* createArray() {
    int* arr = NULL;

    int size = ReadValue<int>("Enter Number of Values: ", 1);

    arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = ReadValue<int>("Value: ");
    }

    return arr;
}

int* evenArray(int* arr) {
    int* evenArr = NULL;
    evenArr = new int[sizeof(arr)];
    int arrIndex = 0;



    for (int i = 0; i < sizeof(arr); i++) {
        if (arr[i] % 2 == 0) {
            evenArr[arrIndex] = arr[i];
            arrIndex++;
        }
    }

    return evenArr;
}

int main() {
    int* arr = createArray();

    int* evenArr = evenArray(arr);

    for (int i = 0; i < sizeof(arr); i++) {
        cout << evenArr[i];
    }


    return 0;
}

```

### 4. Redo question number 3 with these changes. Instead of dynamically allocating an array to store the data, your program will will an STL array. Even numbers will also be copied to an STL array. The input of the data and copying of even numbers will require the program to start at the beginning of the array and walk thorugh the values to the end. This must be done using iterators.
```
#include <iostream>
#include <array>
#include <iterator>
#include <cmath>

#include "input.h"

using namespace std;

int main() {
    array<int, 5> arr;
    array<int, 5> evenArr;
    
    array<int, 5>::iterator ptr;
    array<int, 5>::iterator evenPtr = evenArr.begin();
    
    for (ptr = arr.begin(); ptr < arr.end(); ptr++) {
        *ptr = ReadValue<int>("Value: ");
    }
    
//    for (ptr = arr.begin(); ptr < arr.end(); ptr++) {
//        cout << *ptr;
//    }
    
    for (ptr = arr.begin(); ptr < arr.end(); ptr++) {
        if (*ptr % 2 == 0) {
            *evenPtr = *ptr;
            evenPtr++;
        } else {
            *evenPtr = NULL;
        }
    }
    
    for (evenPtr = evenArr.begin(); *evenPtr != NULL; evenPtr++) {
        cout << *evenPtr;
    }

    return 0;
}

```

### 5. What is the difference between composition and inheritence?

```
Composition is a "has-a" relationship while inheritence is a "is-a". Inheritance BASICALLY is a more strict relationship with composition allows for more flexiblity
```

### 6. What is polymorphism? Be sure to include what role virtual functions play in this and the difference between a virtual and pure virtual funciton. Be sure to include the defintion of an abstract base class.

```
Polymorphism allows the same function or object can act differently in different situations.
```

```
Virtual functions are declared by using the keyword "virtual" and return either int, float, or void. They are able to be "overwritten" to return something else.
```

```
The difference between a virtual function and a pure virtual function is that a pure virtual function is that when the function has no defintion.
```

```
An abstract base class is a class that can represent general concepts which can be used as a base for more concrete classes.
```

### 7. Assume that class B is derived publicly from class A which is abstract. The member functions that are private in class A will be private/protected/public/not directly accessible in class B.

```
not directly accesible in class B
```

### 8. Assume that you have a class that has an integer pointer as a private member. One of the member functions will dynamically allocate memory memory and assign the address to that member. Assume that an object of that class type is instantiated and the funtion called to allocate memory. When the object reaches the end of it's scope - will the memory that has been allocated be released automatically? If not, how would you create a mechanism to accomplish this. Be specific.

```
It will not. So we can use a destructor to get rid of that dynamically allocated memory
```

```
~Class() {
    delete var;
}
```

### 9. What purpose does a copy constructor serve? Under what circumstances is it required?

```
a copy constructor is a function that initializes an object using another object of the same class. You what to use it when you want to duplicate an object.
```

### 10. Create a class that will store a list of names. Your class needs to include a function that will return the name that appears first aphabetically, and another function that should return the name that appears last alphabetically. You also need to include a function that will sort the list alphabetically. The class does not need to be case insensitive. The three functions should make use of the algorithms discussed in this class.

```
#include <iostream>

using namespace std;

class ListNames {
    string names[5] = {"John", "Michael", "Andrew", "Timothy", "Bar"};

    //Bubble Sort
    void sort() {
        string* ptr = names;
        string t;

        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (*(ptr + j) < *(ptr + i)) {
                    t = *(ptr + i);
                    *(ptr + i) = *(ptr + j);
                    *(ptr + j) = t;
                }
            }
        }
    }

    public:
        void printFirst() {
            sort();
            cout << names[0] << "\n";
        }
        void printLast() {
            sort();
            cout << names[4] << "\n";
        }
};
```
