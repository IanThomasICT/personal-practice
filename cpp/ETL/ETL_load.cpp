#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>

/*
 * Part 2 of Scrabble Extract-Transform-Load (ETL) exercise
 *  This is how the Scabble game ought to be loaded using the new system.
 *  The old system was transformed into the "scores.txt" file which is 
 *  loaded into this program to form the new system.
 * 
 */

int main()
{

    // Generate 26-int vector from the text file "scores.txt"
    std::vector<int> scores;
    std::ifstream myfile("scores.txt");
    int data;
    while (!myfile.eof())
    {
        myfile >> data;
        scores.push_back(data);
    }

    // Generate a 26-char alphabet string
    std::string alphabet;
    for (int a = 0; a < 26; a++)
        alphabet += ('a' + a);
    
    // Prompt User
    std::string input;
    std::cout << "Enter your word: ";
    std::getline (std::cin,input);

    char answer;
    int factor;
    std::cout << "Is there a multiplication bonus (y/n)? ";
    std::cin >> answer;

    if (answer == 'y'){
        std::cout << "By what factor? ";
        std::cin >> factor;
    }

    // Calculate score according to the index value of each inputted character
    int word_score = 0;
    for (unsigned long int i=0;i<input.size();i++){
        for (unsigned long int j=0;j<alphabet.size();j++){
            if (std::tolower(input[i]) == alphabet[j]){
                std::cout << input[i] << " is worth " 
                          << scores[j] << " points." << "\n";
                word_score += scores[j];
            } else {
                continue;
            }
        }
    }

    // Multiply score by factor if necessary
    if (answer == 'y'){
        std::cout << "Your word is worth: " << word_score << " points x " 
                  << factor << " for a total of " << word_score * factor
                  << " points!!" << "\n";
    } else
        std::cout << "Your word is worth: " << word_score << " points!" << "\n";

    return 0;
}