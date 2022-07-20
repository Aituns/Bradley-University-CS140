#include <iostream>
#include <climits>
#include <string>

template<typename inputType>

inputType ReadValue(std::string prompt)
{
    inputType returnValue;
    std::cout << prompt;
    std::cin >> returnValue;
    while (std::cin.fail()) {
        std::cout << "Error! Cannot read input.\n";
        std::cin.clear();
        std::cin.ignore(INT_MAX,'\n');
        std::cout << prompt;
        std::cin >> returnValue;
    }
    return returnValue;
}


template<typename inputType>
inputType ReadValue(std::string prompt, inputType minValue)
{
    inputType returnValue=0;
    returnValue=ReadValue<inputType>(prompt);
    while (returnValue < minValue) {
        std::cout << "Error!  Value must be >= " << minValue << std::endl;
        returnValue=ReadValue<inputType>(prompt);
    }
    return returnValue;
}


template<typename inputType>
inputType ReadValue(std::string prompt, inputType minValue, inputType maxValue)
{
    inputType returnValue=0;
    returnValue=ReadValue<inputType>(prompt,minValue);
    while (returnValue > maxValue) {
        std::cout << "Error!  Value must be <= " << maxValue << std::endl;
        returnValue=ReadValue<inputType>(prompt,minValue);
    }
    return returnValue;
}
