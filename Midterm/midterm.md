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

# 3. TODO

# 4. TODO

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

# 10. Create a class that will store a list of names. Your class needs to include a function that will return the name that appears first aphabetically, and another function that should return the name that appears last alphabetically. You also need to include a function that will sort the list alphabetically. The class does not need to be case insensitive. The three functions should make use of the algorithms discussed in this class.
