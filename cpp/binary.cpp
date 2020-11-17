#include <iostream>
#include <string>
#include <cmath>

int main()
{
	int number;
	std::cout << "Enter your number: ";
	std::cin >> number;
	std::string str = std::to_string(number);
	std::cout << "String: " << str << "\n";
	int strsize = str.size();

	bool binary = false;
	for (auto e: str){
		if (e != '0' && e != '1')
			binary = true;
	}
	int num;
	int sum = 0;
	int base10 = 0;
	int base2 = 0;
	if (binary == true){
		for (int i = strsize-1; i >= 0; --i){
			number -= base10;
			num = number/std::pow(10,i);
			base10 = num*(std::pow(10,i));
			sum += base10;
			std::cout << num << "*10^" << i;
			if (i != 0){
				std::cout << " + ";
			}
		}
		std::cout << " = " << sum << " base 10" << "\n"; 
	} else {
		for (int i = strsize-1; i >= 0; --i){
			number = number - base10;
			num = number/std::pow(10,i);
			base10 = num*(std::pow(10,i));	
			base2 = num*(std::pow(2,i));
			sum += base2;
			std::cout << num << "*2^" << i;
			if (i != 0){
				std::cout << " + ";
			}
		}
		std::cout << " = " << sum << " base 10" << "\n";
	}

    return 0;
}
