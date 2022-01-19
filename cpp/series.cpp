#include <iostream>
#include <vector>

int main()
{
    std::string digits;
    std::cout << "Enter your string of digits: ";
    std::getline(std::cin,digits);

    int n;
    std::cout << "Enter the substring length: ";
    std::cin >> n;

    int substring_num = digits.size() + 1 - n;
    std::cout << "Number of substrings: " << substring_num << "\n";

    std::vector<std::string> substrings(substring_num);
    
    for (int i = 0; i < substring_num; ++i){
        substrings[i] = (digits.substr(i,n));
    }

    for (auto e : substrings){
        std::cout << e << "\n";
    }

    return 0;
}