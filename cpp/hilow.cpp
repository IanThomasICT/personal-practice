#include <iostream>
#include <random>

int main()
{
	std::random_device		entropy;
	std::mt19937			engine(entropy());
	std::uniform_int_distribution<int> rnd(1,100);
	
	int ans = rnd(engine);
	int input;
		do {
		std::cout << "Quess: ";
		std::cin >> input;

		if (input == ans)
			break;
		else{
			if (input < ans){
				if (ans - input > 10){
					std::cout << "You are too low\n";
				} else
					std::cout << "You are slightly low\n";
			} else{
				if (input - ans > 10)
					std::cout << "You are too high\n";
				else
					std::cout << "You are slightly high\n";
			}
		}
	} while (input != ans);

	std::cout << "You found it!\n";

	return 0;

}
