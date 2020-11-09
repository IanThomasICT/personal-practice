#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <random>
void setDemo();

int main()
{
    std::vector<int> A{11,3,2,14,100,100,100,100,100,123};

    // Sort a vector O(n*logn)
    sort(A.begin(), A.end());

    bool present = binary_search(A.begin(),A.end(),3);
    present = binary_search(A.begin(),A.end(),4);

    auto it = lower_bound(A.begin(),A.end(),100);
    auto it2 = upper_bound(A.begin(),A.end(), 100);

    std::cout << *it << " " << *it2 << "\n";
    std::cout << it2 - it << "\n"; // This shows how many 100's are in the vector

    for (int &x : A)
        x++;
    for (int x : A)
        std::cout << x << " ";
    std::cout << "\n";
   
    setDemo();
}

void setDemo()
{
    // Random Generator
    std::random_device      entropy;
    std::mt19937         engine(entropy());
    std::uniform_int_distribution<int> num(-200,200);
    
    // Sorts as ints are entered
    std::set<int> S;
    S.insert(1);
    S.insert(2);
    S.insert(-1);
    S.insert(-10);

    for (int x : S)
        std::cout << x << " ";
    std::cout << "\n";

    //-10 -1 1 2
    auto it = S.find(-1); // 
    if (it == S.end())
        std::cout << "not present\n";
    else
        std::cout << "present\n"
                  << *it << "\n";

    auto it2 = S.upper_bound(-1);
    auto it3 = S.upper_bound(0);

    std::cout << "Random Set: ";
    std::set<int> S2;
    for (int i = 0; i < 50; i++)
        S2.insert(num(engine));
    
    for (auto x: S2)
        std::cout << x << " ";
    
    std::cout << "\n";
}