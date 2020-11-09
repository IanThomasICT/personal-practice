#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main()
{
	// read a file
	std::ifstream infile;
	infile.open("input.GRADE1");
	
	std::vector<std::string> words;
	std::string line;
	std::string longest_word = "";
	while (std::getline(infile,line))
	{
		std::istringstream sin(line);
		std::string wrd;
		while (sin >> wrd){
			while (!(tolower(wrd.back()) >= 'a' && tolower(wrd.back()) <= 'z'))
				wrd.pop_back();
			
			words.push_back(wrd);
			
			if (longest_word.size() < wrd.size())
				longest_word = wrd;
		}
	}

	infile.close();

	int wordsize = words.size();
	float average;
	float sum = 0.0;

	for (auto e : words)
		sum += e.size();
	
	average = sum / wordsize;
	
	std::cout.setf(std::ios::fixed);
	std::cout.setf(std::ios::showpoint);
	std::cout.precision(1);


	std::cout << "There are " << wordsize << " words.\n" 
			  << "Longest word: " << longest_word << "\n"
			  << "Average word length: " << average << " letters.\n";


	return 0;
}
