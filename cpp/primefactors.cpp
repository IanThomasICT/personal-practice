#include <iostream>
#include <vector>
#include <random>

int main()
{   
    
    int natural;
    std::cout << "Enter a number: ";
    std::cin >> natural;
    
    std::vector<int> primes{};
    std::vector<int> pfactor;
    bool prime = true;
    for (int i = 2; i <= natural; i++){
        prime = true;
        for (int a = 2; a < (i+1)/2;a++)
            if (i % a == 0)
                prime = false;
        
        if (prime == true)
            primes.push_back(i);
    }
    int nat = natural;
    for (unsigned int i = 0; i < primes.size(); i++)
        if (nat % primes[i] == 0){
            pfactor.push_back(primes[i]);
            nat = nat / primes[i];
            i = i-1;
        }

    if (pfactor.size() > 1){
        std::cout << "The prime factors of " << natural << " are: ";
        for (unsigned int i = 0; i < pfactor.size(); i++){
            if (i != pfactor.size()-1)
                std::cout << pfactor[i] << ", ";
            else
                std::cout << "and " << pfactor[i] << ".";
        }
    } else
        std::cout << natural << " is prime, and has no prime factors.";
    std::cout << "\n";

    return 0;
}