#include <iostream>
#include <random>
#include <fstream>
#include <unistd.h>
#include <array>

std::random_device              entropy;
std::mt19937            engine(entropy());
std::uniform_int_distribution<int>  dist(1,5000);

const int MAX = 500;
void bubble_sort(std::array<int, MAX> &arr);
int main()
{
    std::array<int, MAX> numbers;
    for (int i = 0; i < MAX; ++i){
        numbers[i] = dist(engine);
    }

    std::ofstream outfile;
    outfile.open("numbers.txt");
    if(!outfile){
        std::cout << "Can't find file" << "\n";
    } else {
        std::cout << "Writing to file..." << "\n";
        for (auto e : numbers){
            outfile << e << "\n";
        }
        outfile.close();
        
        unsigned int milliseconds = 1000000;
        usleep(2 * milliseconds);
        bubble_sort(numbers);

        outfile.open("numbers.txt");
        if (!outfile){
            std::cout << "Error adding sorted data.." << "\n";
        } else {
            for (auto e : numbers){
                outfile << e << "\n";
            }
        }

    }

    outfile.close();

    return 0;
}









void bubble_sort(std::array<int, MAX> &arr){
    std::cout << "Sorting data..." << "\n";
    bool sorted = false;
    while (sorted == false){
        bool swapped = false;
        for (int i = 0; i < MAX; ++i){
            for (int j = i; j < MAX; ++j){
                if (arr[j] > arr[j+1]){
                    std::swap(arr[j+1], arr[j]);
                    swapped = true;
                }
            }
        }

        if (swapped == false){
            sorted = true;
        }
    }
    std::cout << "Sorted!" << "\n";
}