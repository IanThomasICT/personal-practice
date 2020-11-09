#include <iostream>
#include <string.h>

// Create a program that prompts for a year and states whether it's a leap year or not

// Leap year parameters:
//  on every year that is evenly divisible by 4
//      except every year that is evenly divisible by 100
//          unless the year is also evenly divisible by 400


int main()
{
    int year;

    std::cout.setf(std::ios::fixed);
    std::cout.precision(4);

    // Prompt
    std::cout << "Enter a Gregorian year: ";
    std::cin >>  year;
    std::cout << "You entered: " << year << "\n";

    // State whether it's a leap year
    if (year % 100 == 0 && year % 400 != 0) {
        std::cout << year << " is NOT a leap year." << "\n";
    } else {
        if (year % 4 == 0) {
            std::cout << year << " is a leap year." << "\n";
        } else {
            std::cout << year << " is NOT a leap year." << "\n";
        }

    }

    return 0;
}