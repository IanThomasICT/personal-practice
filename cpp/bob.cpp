#include <iostream>
#include <string> // std::string, size(), at()
#include <cctype> // toupper()

int main()
{
    std::string input = "";
    while (input != "I'm done") {
        
        // Prompt User
        std::cout << "Speak to Bob: ";
        std::getline (std::cin,input); // getline assigns a string with spaces

        // Create CAPITALIZED input
        std::string input_cap = "";
        for (unsigned long i=0;i<input.size();++i){
            input_cap += toupper(input[i]); // += appends letters to a string
        }

        int inputend = input.at(input.size()-1); // This checks a string's index

        // Bob Response
        if ((inputend == '?') && (input != input_cap)) {
            std::cout << "Sure." << "\n";
        } else if ((inputend == '?') && (input == input_cap)) {
            std::cout << "Calm down, I know what I'm doing!" << "\n";
        } else if (input == input_cap) {
            std::cout << "Whoa, chill out!" << "\n";
        } else if (input == "Bob") {
            std::cout << "Fine. Be that way!" << "\n";
        } else { 
            std::cout << "Whatever." << "\n";
        }
    }
    
    return 0;
}