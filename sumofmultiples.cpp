#include <iostream>

int main()
{
    // Prompt for variables
    int maxim;
    int mult1;
    int mult2;

    std::cout << "Enter the maximum value: ";
    std::cin >> maxim;
    std::cout << "Enter the first multiple: ";
    std::cin >> mult1;
    std::cout << "Enter the second multiple: ";
    std::cin >> mult2;

    int sum = 0;

    std::cout << "From 1 to " << maxim << ", the multiples of " << mult1 
              << " and " << mult2 << " are: ";

    // Find multiples
    for (int i = 1; i < maxim; i++)
        if (i % mult1 == 0 || i % mult2 == 0){
            std::cout << i << " ";
            sum += i;
        }

    // Print sum
    std::cout << "\n" << "The sum of multiples: " << sum << "\n";


    return 0;
}