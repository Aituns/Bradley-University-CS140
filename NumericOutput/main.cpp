/*
 * Austin Bennett
 * CSC 122 - Numeric Output
 * main.cpp
 * this file has all the functionality and will format the number
 *
 *
    Use C-Style strings to do the following:
    Write a function that will take a "double" and C-Style string as a pair of parameters.
    The function will format the number in the following way:
    1. If the number is negative, it will preface the number with a minus '-' sign
    2. If the number is a decimal with no digits to the left of the decimal point,
       it will include a '0' to the left of the decimal point
    3. The number will be shown with 4 digits to the right of the decimal point.
       Pad with zeros if necessary.  For example:   4 -> 4.0000
    4. Commas will be place on the left side of the decimal point in their appropriate place.
       For example:  1,234,567.0000
    5. Write a main function that will prompt the user for a number then call the display function.

 */

#include <iostream>
#include <cmath>

using namespace std;

//Formating function
void Format(double input, char result[]) {

    // resultIndex will handle what goes where in our output
    int resultIndex = 0;

    //Making the input nice to work with
    std::string inputString = to_string(input);
    char num[inputString.length() + 1];
    strcpy(num, inputString.c_str());

    // characteristic is all the numbers on the right of the decimal point
    char* characteristic = strtok(num, ".");
    int characteristicLen = strlen(characteristic);
    int characteristicIndex {0};

    // this adds the commas
    for (int i = characteristicLen - 1 ; i >= 0; i--) {
        bool isComma = ((i + 1) % 3 == 0);

        if (isComma) {
            result[resultIndex] = ',';
            resultIndex++;
            result[resultIndex] = characteristic[characteristicIndex];
            characteristicIndex++;
            resultIndex++;
        } else {
            result[resultIndex] = characteristic[characteristicIndex];
            characteristicIndex++;
            resultIndex++;
        }
    }

    //adds the decimal
    result[resultIndex] = '.';
    resultIndex++;

    // creates the mantissa
    characteristic = strtok(NULL, ".");

    //adds the decimals
    for (int i = 0; i <= 3; i++) {
        result[resultIndex] = characteristic[i]; // the mantissa's value at index i
        resultIndex++;
        characteristicIndex++;
    }

    //prints out the result
    for (size_t i = 0; i < resultIndex; i++) {
        cout << result[i];
    }
}

//
int main() {
    char result[] {};
    double num;

    cout << "Enter your number: ";
    cin >> num;

    Format(num, result);

    return 0;
}
