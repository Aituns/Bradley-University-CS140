#ifndef LIST_H
#define LIST_H

#include <iostream>

class List
{
    private:
        
        
        std::string* temp;

    public:
        std::string* data;
        long size;
        enum {MAX_SIZE=1000};
    
        void Remove(std::string value);
        void Add();
        void Resize(long numValues);
        void Clear();
        void SetValue(std::string value, long pos);
        std::string GetValue(long pos);
        long GetSize();
        void Input(long newSize);
        std::string Display();
        
    
        List();
        List(const List& l);
        ~List();
};

#endif
std::istream& operator>> (std::istream& in, List& l);
std::ostream& operator<< (std::ostream& out, List& l);
