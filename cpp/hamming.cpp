#include <iostream>
#include <string>
#include <time.h>
#include <vector>

// Task: Write a program that randomly generates two 17 char
//       strings with "C","A","G", and "T", then places arrows 
//       beneath the characters that match.

int main(){
    
    srand(time(NULL)); // Randomize the program's seed every run

    std::vector<int> list{1,3,7,20};
    std::string line1 = "";
    std::string line2 = "";
    int i = 0;

    // Generate two random strings of 'DNA' that are 17 char long
    while (i < 17) {
        int ind1 = rand() % list.size();
        int ind2 = rand() % list.size();
        char l1 = '@' + list[ind1];
        char l2 = '@' + list[ind2];
        line1.append(1,l1);
        line2.append(1,l2);
        i++;
    }    


    std::cout << line1 << "\n" << line2 << "\n";
    // Compare strings
        for (unsigned long i=0; i < line1.size();i++){
            if (line1[i] == line2[i]){
                std::cout << "^";
            } else {
                std::cout << " ";
            }
        }
    std::cout << "\n";

    return 0;
}