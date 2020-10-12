#include <iostream>
#include <array>
#include <string>

// Formats phone numbers to a 10-digit string

void formatPhoneNumber(std::string& str);
void printPhoneNumber(std::string str);



int main()
{
    std::array<std::string, 4> numbers{"+1 (613)-995-0253", "613-995-0253", "1 613 995 0253", "613.995.0253"};

    // Optional: Create capability to input phone number string

    // Go through array elements
    for (int i = 0; i < numbers.size(); i++){
        std::string str = numbers[i];
        formatPhoneNumber(str); // Optional: Convert string to int
        printPhoneNumber(str);
     }


    return 0;
}







void formatPhoneNumber(std::string& str)
{
    for (int s = 0; s < str.length(); s++){
            if (str[s] == ' ' || str[s] == '-' || str[s] == '.')
                for (int j = s; j < str.length(); j++){
                    str[j] = str[j+1];
                }
            else if (str[s] == '(' || str[s] == ')'){
                for (int j = s; j < str.length(); j++)
                    str[j] = str[j+1];
                }
            else if (str[s] == '+' && str[s+1] == '1')
                for (int j = s; j < str.length(); j++){
                    str[j] = str[j + 2];
                    str[j+1] = str[j + 2]; 
                }
            else if (str[s] == '1' && str[s+1] == ' ') // Special case
                for (int j = s; j < str.length(); j++){
                    str[j] = str[j + 2];
                    str[j+1] = str[j + 2]; 
                }
    }

    // Check again for any missed errors
    for (int s = 0; s < str.length(); s++){
            if (str[s] == ' ' || str[s] == '-' || str[s] == '.')
                for (int j = s; j < str.length(); j++){
                    str[j] = str[j+1];
                }
            else if (str[s] == '(' || str[s] == ')'){
                for (int j = s; j < str.length(); j++)
                    str[j] = str[j+1];
                }
            else if (str[s] == '+' && str[s+1] == '1')
                for (int j = s; j < str.length(); j++){
                    str[j] = str[j + 2];
                    str[j+1] = str[j + 2]; 
                }
            else if (str[s] == '1' && str[s+1] == ' ') // Special case
                for (int j = s; j < str.length(); j++){
                    str[j] = str[j + 2];
                    str[j+1] = str[j + 2]; 
                }
    }
    str.resize(10);
    for (int c = 0; c < 10; c++)
        str[c] = std::stoi(str[c]);
}

void printPhoneNumber(std::string str)
{
    str.resize(10);
    std:: cout << str << "\n";
}