#include <iostream>
#include <utility>

int main()
{
    std::string input;
    std::cout << "Please enter a phrase: ";
    std::getline(std::cin,input);

    std::pair<char,int> letters[10];


    letters[0].first = 'A';
    letters[0].second = 10;

    std::cout << letters[0].first << ", " << letters[0].second << "\n";


    return 0;
}