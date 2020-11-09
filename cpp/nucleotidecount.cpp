#include <iostream>
#include <array>
#include <random>

using namespace std;

void strandCount(string strand, array<int,4> &nucleotide);

int main()
{
    // Randomly generate a string
    std::random_device                       entropy;
    std::mt19937                   engine(entropy());
    std::uniform_int_distribution<int>    index(0,3);
    std::uniform_int_distribution<int>  strlen(4,30);

    int stringLength = strlen(engine);

    // Array of characters
    array<char,4> letters{'A','C','G','T'};

    // Identify a DNA string of unknown lenth with {A,C,G,T} characters
    string strand;

    for (int l = 0; l < stringLength; l++){
        int tmp_i = index(engine);
        strand += letters[tmp_i];
    }

    cout << "Your strand is: " << strand << "\n";

    // Create empty array to store letter count
    array<int,4> nucleotide{0,0,0,0}; // {A, C, G, T}
    
    strandCount(strand,nucleotide);

    // Print the count
    cout << "A: " << nucleotide[0] << "\n"
              << "C: " << nucleotide[1] << "\n"
              << "G: " << nucleotide[2] << "\n"
              << "T: " << nucleotide[3] << "\n";

    return 0;
}

void strandCount(string strand, array<int,4> &nucleotide)
{
    for (int i = 0; i < strand.size(); i++){
        switch(strand[i]){
            case 'A':
                nucleotide[0]++;
                break;
            case 'C':
                nucleotide[1]++;
                break;
            case 'G':
                nucleotide[2]++;
                break;
            case 'T':
                nucleotide[3]++;
                break;
        }
    }
}