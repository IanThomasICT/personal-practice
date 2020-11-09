#include <iostream>
#include <string.h>

// Write a program that detects whether a string is an isogram or not
// Isogram = A word that does not contain more than 1 of the same letter


int main()
{

    std::string input = "";

    // Ask for input
    std::cout << "Please enter your word: ";
    std::cin >> input;

    // Determine whether the string is an isogram
    bool check = false;
    
    unsigned int i;
    unsigned int others;
    for (i=0; i < input.size();i++) // Extract every letter starting from index 0
    {
        for (others=i+1; others < input.size();others++) {// Check for match with all other letters
            if (input[i] == input[others]) {
                check = true;
            }
        }
    }


    // Print out the result
    if (check){
        std::cout << "Your word is NOT an isogram." << "\n";
    } else {
        std::cout << "Your word is an isogram!" << "\n";
    }



}