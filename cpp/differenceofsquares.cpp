#include <iostream>
#include <random>

/* Function finds the square of the sum of intergers from 0 to n
 *
 * Parameters:
 *      n: int, value which is the last value added in the sum
 * 
 * Returns:
 *      sumSquared: int, the result or square of the sum of integers from [0,n]
 */
int sumSquared(int n);

/* Function finds the sum of the squares of integers from 0 to n
 *
 * Parameters:
 *      n: int, value which is the last squared value in the sum
 * 
 * Returns:
 *      squaredSum: int, the result or sum of the squares of integers from [0,n]
 */
int squaredSum(int n);

/* Function prints the difference between two values
 *
 * Parameters:
 *      firstval: int, first value that will be subtracted from
 *      secondval: int, second value that will be subtracted
 */
void printDifference(int firstval, int secondval);


int main()
{
    // Random number generator for range [1,20]
    std::random_device                     entropy;
    std::mt19937                 engine(entropy());
    std::uniform_int_distribution<int>  dist(1,20);
    
    // Randomly pick a number between [1,20]
    int n = dist(engine);
    std::cout << n << " is your number n." << "\n";

    // Prints the difference of sumSquared and squaredSum functions
    printDifference(sumSquared(n),squaredSum(n));

    return 0;
}










int sumSquared(int n)
{
    // Find the square of the sum of intergers from 0 to N {(1 + 2 + ... + N)^2}
    int sumSquared = 0;
    for (int i = 1; i <= n; i++){
        sumSquared += i;
    }
    sumSquared = sumSquared*sumSquared;
    std::cout << "Your first value is: " << sumSquared << "\n";

    return sumSquared;    
}

int squaredSum(int n)
{
    // Find the sum of the squares of integers from 0 to N {1^2 + 2^2 + ... N^2}
    int squaredSum = 0;
    for (int a = 1; a <= n; a++){
        squaredSum += (a*a);
    }

    std::cout << "Your second value is: " << squaredSum << "\n";    

    return squaredSum;
}

void printDifference(int firstval, int secondval)
{
    // Print the difference between the two values
    int difference = firstval - secondval;
    std::cout << firstval << " - " << secondval << " = " << difference << "\n";

    return;    
}