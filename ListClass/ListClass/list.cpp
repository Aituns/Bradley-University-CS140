#include "list.h"
#include "input.h"

#include <exception>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator>

using namespace std;

void List::Clear()
{
    if (size > 0)
    {
        delete[] data;
        size = 0;
        data = nullptr;
    }
}

void List::Resize(long numValues)
{
    try
    {
        if (numValues < 1 || numValues > MAX_SIZE)
        {
            throw "Error! Invalid list size specified.";
        }
        
        if (size == 0) {
            Clear();
            data = new double[numValues];
            
            if (data == nullptr)
            {
                throw "Error! Could not allocate memory for list.";
            }
            
            size = numValues;
        
        } else {
            temp = new double[size];
            long tempSize = size;
            copy(data, data+numValues, temp);
            
            Clear();
            data = new double[numValues];
            size = numValues;
            
            for (int i = 0; i < tempSize; i++){
                data[i] = temp[i];
            }
            
            delete[] temp;
        }
    }
    catch (std::exception &e)
    {
        throw "Error! Could not allocate memory for list.";
    }
}

void List::SetValue(double value, long pos)
{
    if (pos < 0 || pos >= size)
    {
        throw "Error! Invalid position in list specified.";
    }
    data[pos] = value;
}

double List::GetValue(long pos)
{
    if (pos < 0 || pos >= size)
    {
        throw "Error! Invalid position in list specified.";
    }
    return data[pos];
}

//Bubble Sort beacuse I'm too lazy to add Quick Sort
void List::BubbleSort() {
    double* ptr = data;
    int i, j, t;
    
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (*(ptr + j) < *(ptr + i)) {
                t = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = t;
            }
        }
    }
}

double List::Median() {
    // Cases: Odd or Even
    // Sort -> check odd or even -> find the middle of list

    bool isEven = (size % 2 == 0);
    int midIndex = ceil(size/2);
    double median = NULL;
    double* ptr = data;
    
    // Sort
    BubbleSort();
    
    // Check if Odd or Even
    if (isEven) {
        // find the middle of the list
        median = (ptr[midIndex] + ptr[midIndex - 1]) / 2;
    } else {
        // find the middle of the list
        median = (double)ptr[size / 2];
    }

    return median;
}

double List::Average() {
    double total = NULL;
    
    for (double *ptr = data; ptr < data + size; ptr++)
    {
        total += *ptr;
    }
    
    return total / size;
}

void List::Input()
{
    try
    {
        if (size == 0)
        {
            long x = ReadValue<long>("Number of values? ");
            Resize(x);
        }

        for (double *ptr = data; ptr < data + size; ptr++)
        {
            *ptr = ReadValue<double>("Value? ");
        }
    }
    catch (const char *s)
    {
        throw s;
    }
}

void List::Display()
{
    if (size > 0)
    {
        std::cout << "List values:\n";
        for (double *ptr = data; ptr < data + size; ptr++)
        {
            std::cout << *ptr << " ";
        }
        std::cout << std::endl;
        
    }
    else
    {
        std::cout << "List is empty.\n";
    }
}

long List::GetSize() {
    return size;
}

List::List()
{
    data = nullptr;
    size = 0;
}

List::~List()
{
    Clear();
}
