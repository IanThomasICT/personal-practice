#include <iostream>
#include <vector>

using std::endl;
using std::cout;

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int max = nums[0];
        int sum = 0;
        unsigned int range[2];
        cout << "Starting calculation of vector with size of: " << nums.size() << endl;
        for (unsigned int i = 0; i < nums.size(); ++i){
            sum = 0;
            for (unsigned int j = i; j < nums.size(); ++j){
                sum += nums[j];
                if (sum > max){
                    max = sum;
                    range[1] = i; range[2] = j;
                }
            }
        }   

        auto start = nums.begin()+range[1];
        auto end = start + range[2];
        std::vector<int> result(start, end);

        cout << "[";
        for (auto e : result){
            cout << e << " ";
        }
        cout << "] has the largest sum = " << max << endl;

        return 0;
    }

};

int main()
{
    std::vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout << s.maxSubArray(nums) << endl;



}