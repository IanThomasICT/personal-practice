#include <iostream>
#include <string>

// Reverse a given string

int main()
{
    std::string input;
    std::string result;

    // Prompt for a string
    std::cout << "Enter your string: ";
    std::getline(std::cin,input);   // Reads the whole line of cin input until a new line ("ENTER"
    unsigned long size = input.size();

    // Reverse the string
    unsigned long i;

    for (i=0;i <= size;i++){ // Take the max index value and subtract i from it as i increments
        result += input[size-i]; // Append (add) each indexed character of the string to a new empty string
    }

    std::cout << "Your string reversed is: " << result << ". \n";

    return 0;
}