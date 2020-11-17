#include <iostream>
#include <vector>

int main()
{
    int maxcount;
    std::cout << "*** Sieve of Eratosthenes ***" << "\n"
              << "Enter the max value: "; 
    std::cin >> maxcount;
    std::cout << "Counting primes from 0 to " << maxcount << "...\n";

    std::vector<int> range;

    for (int i = 2; i <= maxcount; ++i){
        range.push_back(i);
    }

    // Identifies primes by removing multiples of i
    for (unsigned int i = 0; i < range.size(); ++i){
        for (int s = i+1; s < range.size(); ++s){
            if (range[s] % range[i] == 0){
                range.erase(range.begin()+s);
            }
        }
    }

    for (auto e : range){
        std::cout << e << " ";
    }
    std::cout << "\n";

    return 0;
}
