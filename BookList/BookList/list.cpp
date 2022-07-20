#include "list.h"
#include "input.h"

#include <exception>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator>

void List::Clear()
{
    if (size > 0)
    {
        delete[] data;
        size = 0;
        data = nullptr;
    }
}

std::string List::Display()
{
    std::string result;
    if (size > 0)
    {
        std::cout << "List values:\n";
        for (std::string *ptr = data; ptr < data + size; ptr++)
        {
            result = result + *ptr + " ";
        }
    }
    else
    {
        result = "List is empty.\n";
    }
    
    return result;
}

// There must be a function to allow the list size to be increased without losing data that has been previously stored in the list.
void List::Resize(long numValues)
{
    try
    {
        if (numValues < 1 || numValues > MAX_SIZE)
        {
            throw "Error! Invalid list size specified.";
        }

        if (size == 0)
        {
            Clear();
            data = new std::string[numValues];

            if (data == nullptr)
            {
                throw "Error! Could not allocate memory for list.";
            }

            size = numValues;
        }
        else
        {
            temp = new std::string[size + numValues];
            
            copy(data, data + size, temp);

            Clear();
            data = new std::string[size + numValues];
            
            std::string *tempPtr = temp;
            
            for (std::string *ptr=data; ptr<data+size+numValues; ptr++) {
                *ptr= *tempPtr;
            }
            
            size = numValues + size;

            delete[] temp;
        }
    }
    catch (std::exception &e)
    {
        throw "Error! Could not allocate memory for list.";
    }
}

void List::SetValue(std::string value, long pos)
{
    if (pos < 0 || pos >= size)
    {
        throw "Error! Invalid position in list specified.";
    }
    data[pos] = value;
}

std::string List::GetValue(long pos)
{
    if (pos < 0 || pos >= size)
    {
        throw "Error! Invalid position in list specified.";
    }
    return data[pos];
}

void List::Remove(std::string value)
{
    int index;
    for (int i = 0; i < size; i++)
    {
        if (data[i] == value)
        {
            index = i;
        }
    }

    for (int i = index; i < size; i++)
        data[i] = data[i + 1];
}

void List::Add()
{
    try {
            long x=ReadValue<long>("Number of values? ");
            Resize(x);
        if (size == 0) {
           for (std::string *ptr=data; ptr<data+size; ptr++) {
               *ptr=ReadValue<std::string>("Value? ");
           }
        } else {
            for (std::string *ptr=data; ptr<data+size+x; ptr++) {
                *ptr=ReadValue<std::string>("Value? ");
            }
        }
       }
       catch (const char* s) {
           throw s;
       }
}

std::ostream &operator<<(std::ostream &out, List &l)
{
    out << l.Display();
    return out;
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

List::List(const List &x)
{
    size = x.size;
    data = new std::string[size];
    for (long i = 0; i < x.size; i++)
    {
        data[i] = x.data[i];
    }
}
