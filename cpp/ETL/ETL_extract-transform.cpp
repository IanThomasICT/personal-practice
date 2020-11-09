#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>

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

    // Converts Old System of 7 lists to a 26-int vector: alphabet_scores
    for (unsigned long i=0;i<26;++i){
        char letters = 'a' + i;    
        for (unsigned long j=0;j<(sizeof(point1)/sizeof(point1[0]));j++){
            if (toupper(letters) == point1[j]){
                alphabet_scores.push_back(1);
            } else {
                continue;
            }
        }
        for (unsigned long k=0;k<(sizeof(point2)/sizeof(point2[0]));k++){
            if (toupper(letters) == point2[k]){
                alphabet_scores.push_back(2);
            } else {
                continue;
            }
        }
        for (unsigned long l=0;l<(sizeof(point3)/sizeof(point3[0]));l++){
            if (toupper(letters) == point3[l]){
                alphabet_scores.push_back(3);
            } else {
                continue;
            }
        }
        for (unsigned long m=0;m<(sizeof(point4)/sizeof(point4[0]));m++){
            if (toupper(letters) == point4[m]){
                alphabet_scores.push_back(4);
            } else {
                continue;
            }
        }
        for (unsigned long n=0;n<(sizeof(point5)/sizeof(point5[0]));n++){
            if (toupper(letters) == point5[n]){
                alphabet_scores.push_back(5);
            } else {
                continue;
            }
        }
        for (unsigned long o=0;o<(sizeof(point8)/sizeof(point8[0]));o++){
            if (toupper(letters) == point8[o]){
                alphabet_scores.push_back(8);
            } else {
                continue;
            }
        }
        for (unsigned long p=0;p<(sizeof(point10)/sizeof(point10[0]));p++){
            if (toupper(letters) == point10[p]){
                alphabet_scores.push_back(10);
            } else {
                continue;
            }
        }
    }

    // Write Scores vector into a text file to be retrieved later
    std::ofstream myfile("scores.txt");
    for (int i = 0; i < alphabet_scores.size();i++)
        myfile << alphabet_scores[i] << "\n";

    return 0;
}