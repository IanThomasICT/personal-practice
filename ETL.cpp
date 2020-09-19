#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // Old Point System
    char point1[] =  {'A', 'E', 'I', 'O', 'U', 'L', 'N', 'R', 'S', 'T'};
    char point2[] = {'D', 'G'};
    char point3[] = {'B', 'C', 'M', 'P'};
    char point4[] = {'F', 'H', 'V', 'W', 'Y'};
    char point5[] = {'K'};
    char point8[] = {'J', 'X'};
    char point10[] = {'Q', 'Z'};
    
    std::vector<int> alphabet_scores;
    std::vector<char> alphabet;

    // Converts Old System of 7 lists to two vectors: alphabet, alphabet_scores
    for (int i=0;i<26;++i){
        char letters = 'a' + i;    
        for (int j=0;j<(sizeof(point1)/sizeof(point1[0]));j++){
            if (toupper(letters) == point1[j]){
                alphabet_scores.push_back(1);
            } else {
                continue;
            }
        }
        for (int k=0;k<(sizeof(point2)/sizeof(point2[0]));k++){
            if (toupper(letters) == point2[k]){
                alphabet_scores.push_back(2);
            } else {
                continue;
            }
        }
        for (int l=0;l<(sizeof(point3)/sizeof(point3[0]));l++){
            if (toupper(letters) == point3[l]){
                alphabet_scores.push_back(3);
            } else {
                continue;
            }
        }
        for (int m=0;m<(sizeof(point4)/sizeof(point4[0]));m++){
            if (toupper(letters) == point4[m]){
                alphabet_scores.push_back(4);
            } else {
                continue;
            }
        }
        for (int n=0;n<(sizeof(point5)/sizeof(point5[0]));n++){
            if (toupper(letters) == point5[n]){
                alphabet_scores.push_back(5);
            } else {
                continue;
            }
        }
        for (int o=0;o<(sizeof(point8)/sizeof(point8[0]));o++){
            if (toupper(letters) == point8[o]){
                alphabet_scores.push_back(8);
            } else {
                continue;
            }
        }
        for (int p=0;p<(sizeof(point10)/sizeof(point10[0]));p++){
            if (toupper(letters) == point10[p]){
                alphabet_scores.push_back(10);
            } else {
                continue;
            }
        }
        alphabet.push_back(letters);
    }

    // Prints letters and points side-by-side
    // for (int a=0;a<alphabet_scores.size();a++){
    //     char letter = 'a'+a;
    //     std::cout << alphabet_scores[a] << "  " << letter << "\n";
    // }

    // Prompt User
    std::string input;
    std::cout << "Enter your word: ";
    std::getline (std::cin,input);

    // Calculate score by each individual letter
    int word_score = 0;
    for (int i=0;i<input.size();i++){
        for (int j=0;j<alphabet.size();j++){
            if (input[i] == alphabet[j]){
                std::cout << input[i] << " is worth " 
                          << alphabet_scores[j] << " points." << "\n";
                word_score += alphabet_scores[j];
            } else {
                continue;
            }
        }
    }

    std::cout << "Your word is worth: " << word_score << " points!" << "\n";

    return 0;
}

