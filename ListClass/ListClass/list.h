#ifndef LIST_H
#define LIST_H

class List
{
private:
    double *data;
    long size;
    double *temp;

public:
    enum
    {
        MAX_SIZE = 1000
    };
    
    void Resize(long numValues);
    void Clear();
    void BubbleSort();
    double Median();
    double Average();
    void SetValue(double value, long pos);
    double GetValue(long pos);
    long GetSize();
    void Input();
    void Display();
    List();
    ~List();
};

#endif
