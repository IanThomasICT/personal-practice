#include <iostream>
#include <math.h>
#include <vector>

int main()
{
	int n;
	std::cout << "How many primes would you like to count to? ";
	std::cin >> n;
	std::vector<int> primes;
	bool isprime;
	int x = 0;
	for (int i = 2; i < 50*n; i++){
		isprime = true;
		for (int j = 2; j < i; j++){
			if (i % j == 0){
				isprime = false;
			}
		}

		if (isprime == true){
			primes.push_back(i);
			x++;
		}

		if (x >= n)
			break;
	}
	
	for (auto e:primes)
		std::cout << e << " ";
	
	std::cout << "\n";
	std::cout << primes.back() << " is the " << n << "th prime.\n";

	return 0;
}
