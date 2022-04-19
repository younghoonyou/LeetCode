#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{//O(N)
public:
    void moveZeroes(vector<int> &nums){
        int idx = 0;
        while (nums[idx] && idx < nums.size() - 1)
            idx++;
        if (idx == nums.size() - 1)
            return;
        for (int i = idx; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
                swap(nums[idx], nums[i]), idx++;
        }
    }
};

int main() {}