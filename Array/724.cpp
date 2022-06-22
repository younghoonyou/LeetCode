#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    int pivotIndex(vector<int> &nums){
        int sum = 0;
        for (int x : nums) sum += x;
        int cal = 0;
        for (int i = 0; i < nums.size(); ++i){
            cal += nums[i];
            if (cal == sum - cal + nums[i]) return i;
        }
        return -1;
    }
};

int main()
{
}