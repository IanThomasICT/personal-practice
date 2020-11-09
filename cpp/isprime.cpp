#include <iostream>
#include <random>
#include <math.h>

bool isprime(int);

int main()
{
	std::random_device		entropy;
	std::mt19937		engine(entropy());
	std::uniform_int_distribution<int> rnd(1,25000);

	std::cout <<	isprime(rnd(engine)) << std::endl;
	std::cout <<	isprime(rnd(engine)) << std::endl;
	std::cout <<	isprime(rnd(engine)) << std::endl;
	std::cout <<	isprime(rnd(engine)) << std::endl;
	std::cout <<	isprime(rnd(engine)) << std::endl;
	
	return 0;
}

bool isprime(int num)
{
	int range = std::ceil(sqrt(num));
	std::cout << num << " ";
	for (int i =2; i <= range; i++){
		if (num % i == 0){
			std::cout << "is not prime. ";
			return false;
		}
	}

	std::cout << "is prime. ";
	return true;
}

