//
//  main.cpp
//  Recursion
//
//  Created by Austin Bennett on 7/15/22.
//

/*
 1.  Rewrite the Bubble sort to use recursion.

 2.  Use the time(0) function to determine how many seconds it takes to sort a vector using the recursive method.

 3.  Use the time(0) function to determine how many seconds it takes to sort a vector using the non-recursive method described in the videos.

 Run the sort test on vectors containing random integers.  You should sort vectors of the following sizes: 100 elements, 1000 elements, 5,000 elements, 10,000 elements and 50,000 elements.

 Was the recursive method able to work on vectors of each of those sizes?  If not, explain why it errored.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubbleSortRecursive(vector<int> &list, long n)
{
    if (n == 1)
    {
        
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (list[i] > list[i + 1])
        {
            swap(list[i], list[i + 1]);
        }
    }
    bubbleSortRecursive(list, n - 1);
}

void bubbleSort(vector<int> &list, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (list[j] > list[j + 1])
                swap(list[j], list[j + 1]);
        }
    }
}

vector<int> makeList(int size)
{
    vector<int> list;
    for (int i = 0; i < size; i++)
    {
        int num = rand() % 9;
        list.push_back(num);
    }
    return list;
}

int main()
{

    time_t begin, end;
    time(&begin);
    // 100 elements, 1000 elements, 5,000 elements, 10,000 elements and 50,000 elements.
    vector<int> list = makeList(50000);

    bubbleSort(list, list.size());
    
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << " ";
    }

    cout << endl;

    time(&end);
    time_t elapsed = end - begin;

    cout << elapsed << endl;
}

// Recursive
// 100: 0, 1000: 0, 5000: 0, 10000: 1, 50000: 16

// Iterative
// 100: 0, 1000: 0, 5000: 0, 10000: 1, 50000: 16


