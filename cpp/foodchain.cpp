#include <iostream>

using namespace std;

int main()
{
    
    const int SIZE = 8;
    string animals[SIZE]{"fly","spider", "bird", "cat", 
                      "dog", "goat", "cow", "horse"};

    
    // Start at the first verse
    int vrs = 0;
    do {
        for (vrs = 0; vrs < SIZE-1; vrs++){
                cout << "I know an old lady who swallowed a " << animals[vrs] << endl;

                // Unique verses that start after the first section
                if (vrs > 0){
                    switch(vrs){
                        case 1:
                            cout << "It wriggled and jiggled and tickled inside her.\n";
                            break;
                        case 2:
                            cout << "How absurd to swallow a bird!\n";
                            break;
                        case 3:
                            cout << "Imagine that, to swallow a cat!\n";
                            break;
                        case 4:
                            cout << "What a hog, to swallow a dog!\n";
                            break;
                        case 5:
                            cout << "Just opened her throat and swallowed a goat!\n";
                            break;
                        case 6:
                            cout << "I don't know how she swallowed a cow!\n";
                            break;
                    }
                    
                    // She swallowed the ... to catch the ... loop
                    for (int subvrs = vrs; subvrs > 0; subvrs--){
                        cout << "She swallowed the " << animals[subvrs] << " to catch the "
                            << animals[subvrs-1] << ".\n";
                    }
                }
                
                cout << "I don't know why she swallowed the fly. Perhaps she'll die.\n\n";
        }
    } while (vrs < 7);
    
    cout << "I know an old lady who swallowed a horse." << endl 
         <<  "She's dead, of course!\n";
   
    return 0;
}