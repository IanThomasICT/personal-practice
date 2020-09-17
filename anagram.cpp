#include <iostream>
#include <algorithm>

using namespace std;

// Task: Given a string, identify which of the 4 choices are an anagram of the string

int main()
{

    string word = "test";
    // Prompt for string
    cout << "Enter a word and we'll find the anagram: ";
    cin >> word;

    // Sort string
    sort(word.begin(),word.end());

    string wordlist[] = {"enlists","google","inlets","banana"};
    string sort_wordlist[] = {"enlists","google","inlets","banana"};

    sort(sort_wordlist[3].begin(),sort_wordlist[3].end());
    int anagramindex;
    for (unsigned long i = 0; i < 4;++i) { 
        sort(sort_wordlist[i].begin(),sort_wordlist[i].end());
        if (sort_wordlist[i] == word) {
            anagramindex = i;
        } else {
            continue;
        }
    }

    cout << "Out of the following: "
         << wordlist[0] << ", " << wordlist[1] << ", " 
         << wordlist[2] << ", " << wordlist[3] << "\n"
         <<  "'" << wordlist[anagramindex] << "' is an anagram." << "\n";

    return 0;
}