//
//  main.cpp
//  CompoundingInterest
//
//  Created by Austin Bennett on 6/19/22.
//

/*
 Write a program that read the starting balance, interest rate and number of months from a file.
 Example:
 1200.43  .08 60
 (Balance of $1200.43, 8 percent interest rate, 60 months)
 your program will print out a table showing month number and current balance (assume it is compounded monthly) for the number of specified months.  Your program should prompt the user for the name of the output file.  Use the formatting function you created previously to format the amount.  Please note that the output of the program must show balance each month - not just the total at the end.
 Example:
 0 1,200.43
 1 1,208.44
 2 1,216.54
 etc.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string Format(double input) {
    
    char result[] {};

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
    for (int i = 0; i <= 1; i++) {
        result[resultIndex] = characteristic[i]; // the mantissa's value at index i
        resultIndex++;
        characteristicIndex++;
    }

    //builds out the result
    
    string s = "";
    for (size_t i = 0; i < resultIndex; i++) {
        s = s + result[i];
    }
    
    return s;
}


int main()
{
    // Get intial values
    float newBalance, interestRate, months, oldBalance;
    fstream input("/Users/austin/Documents/School/Summer 2022/CSC 122/CompoundingInterest/CompoundingInterest/input.txt", ios_base::in);
    input >> oldBalance >> interestRate >> months;
    
    // Build the output file
    string fileName;
    cout << "Enter File Name (No extension): ";
    cin >> fileName;
    ofstream output;
    output.open ("/Users/austin/Documents/School/Summer 2022/CSC 122/CompoundingInterest/CompoundingInterest/" + fileName + ".txt");
      
    //Assuming the first month counts as one of the input months
    output << "0 " << Format(oldBalance) << endl;
    for (int i = 1; i < months; i++) {
        newBalance = ( 1 + interestRate / 12 ) * oldBalance;
        output << i << " " << Format(newBalance) << endl;
        oldBalance = newBalance;
    }
}
