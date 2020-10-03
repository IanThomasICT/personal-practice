#include <iostream>
#include <string>
#include <algorithm>
#include <array>

using namespace std;

// TODO
//  - Figure out how to jump special characters similar to spaces (!, ?, .)

// Write a program that counts the number of words in a string
// and how many times each word appears (regardless of case or apostrophes)

int main()
{
    // Prompt for sentence
    string input;

    cout << "*** Word Count Checker! ***" << "\n"
              << "Enter a sentence: ";
    getline (cin, input);

    int wordcount = 1;
    // Count number of words
    for (int i = 0; i < input.size(); ++i){
        if (input[i] == ' ')
            wordcount++;  
    }
    
    const int WORDCOUNT = wordcount;
    cout << wordcount << "\n";
    // Create empty array
    string words[WORDCOUNT];

    // Separate word strings and store in array
    int endpoint = 0;                                                               // hello, my name is Ian ian
    for (int w = 0; w < wordcount; w++){  // Writing elements to words[w]           // 
        for (int i = endpoint; endpoint < input.size(); ++i){                       
            if ((input[i] >= 'a' && input[i] <= 'z') ||                             
                 (input[i] >= 'A' && input[i] <= 'Z') ||                            
                 (input[i] == '\'')){                                               
                char letter = tolower(input[i]);
                words[w] += letter;
                endpoint++;
            } else if (input[i] == ',' || input[i] == '!' || input[i] == '.') { 
                endpoint = i+1;
            } else {
                endpoint = i+1;
                break;
            }
        }
    }



    for (auto i : words)
        cout << i << " | ";

    cout << "\n";

    // Print the number of times the word strings are use
    for (int r = 0; r < wordcount; r++){
        int score = 1;
        for (int c = r+1; c < wordcount; c++){
            // If a duplicate is found, increase the word's score and remove the duplicate
            if (words[r] == words[c]){
                score++;
                wordcount--;
                for (int j = c; j < wordcount; j++){ // Removes the duplicate
                    words[j] = words[j+1];
                }
            } else if (words[c] == " "){
                wordcount--;
                for (int j = c; j < wordcount; j++){ // Removes the duplicate
                    words[j] = words[j+1];
                }
            } 
            else
                continue;
        }
        cout << "   " << words[r] << ": " << score << "\n";
    }

    cout << "\n";

    return 0;
}
