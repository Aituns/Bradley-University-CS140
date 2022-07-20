/*
 Add the following functionality to the list class to do the following:

 Add a function to sort the data, calculate the average and determine the median.

 Also modify the Resize() function to do the following:

 Allow the function to resize the modify the size of the array.  If the new size is larger than the old size, the data values in the array should be copied into the new.
    -> If the new array is smaller than the original, it should copy only as many values as the new array will hold.

 Use this class to write a program to allow the user to enter a list of values, then display the list, sort and redisplay the list and display the average and median.
 Also resize the list to a larger size, display then resize to a smaller size and redisplay to demonstrate the resizing functionality.
 */


#include <iostream>
#include "list.h"
#include "input.h"

using namespace std;


int main()
{
    try {
        List l;
        
        // "enter a list of values"
        l.Input();
        
        // "display the list"
        l.Display();
        
        // "sort and redisplay the list"
        l.BubbleSort();
        l.Display();
        
        // "display the average and median"
        cout << "Median: " << l.Median() << endl;
        cout << "Average: " << l.Average() << endl;
        
        // "resize the list to a larger size"
        long x = ReadValue<long>("New Size? ");
        l.Resize(x);
        
        // "display then resize to a smaller size"
        l.Display();
        x = ReadValue<long>("New Size? ");
        l.Resize(x);
        
        // "redisplay"
        l.Display();
        
    }
    catch (const char* s) {
        cerr << s << endl;
    }
    return 0;
}
