#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <math.h>

int main()
{
	// Prompt for string
	std::string input;
	std::cout << "Enter your message here: ";
	std::getline(std::cin, input);

	// Format string (Remove spaces/non-lettered ascii chars)
	std::stringstream ss;
	for (auto e : input){
		char letter = tolower(e);
		if (letter >= 'a' && letter <= 'z')
			ss << letter;
	}
	
	std::string formatted;
	ss >> formatted;

	int squaresize = std::ceil(sqrt(formatted.size()));
//	std::cout << "ss: << " << ss.str() << "\n";
//	std::cout << formatted << " " << squaresize << "\n";

	// Create a square with words
	std::vector<std::vector<char>> square(squaresize, std::vector<char> (squaresize));
	char tmp;
	int t =0;
	for (int i = 0; i < squaresize; i++){
		for (int j =0; j < squaresize; j++){
			if (t > formatted.size()-1)
				square[i][j] = '#';
			else 
				square[i][j] = formatted[t++];
//			std::cout << square[i][j] << " ";
		}
//		std::cout << "\n";
	}
	
	// Create new strings by reading the columns
	
	std::string result = "";
	for (int j = 0; j < squaresize; j++){
		for (int i = 0; i < squaresize; i++){
			if (square[i][j] != '#'){
				result += square[i][j];
			}
		}
		if (j != squaresize-1)
			result += " ";
	}

	std::cout << result << "\n";
	// Print new strings
}

