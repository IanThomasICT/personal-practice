#include <iostream>
#include <vector>

int main()
{

    std::vector<std::string> nums{"john","sally", "james"};

    for (auto e : nums)
        std::cout << e << " ";


    return 0;
}