#include <iostream>
#include <string> 
#include <sstream>

int main()
{
    std::string input;
    std::getline(std::cin,input);

    std::stringstream result;
    int size = input.size();

    if (input[0] >= 'a' && input[0] <= 'z'){
        if (size-2 > 9){
            std::string tmp =  input[0] + size-2 + input[input.size()-1];
            input = tmp;
        } else
            input = ""; 
    }

    
    std::cout << input;
    
    return 0;
}