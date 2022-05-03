#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution{
public:
    int findUnsortedSubarray(vector<int> &nums){//O(2N)
        int val = -100001;//standard
        int s_idx, e_idx;//return val
        s_idx = e_idx = 0;
        for (int i = 0; i < nums.size(); ++i){//from start to end
            if (val < nums[i]) val = nums[i];
            else if (val > nums[i]) s_idx = i;//I should record idx when smaller than maximum val
        }
        val = 100001;
        for (int i = nums.size() - 1; i >= 0; i--){//from end to start
            if (val > nums[i]) val = nums[i];
            else if (val < nums[i]) e_idx = i; // I should record idx when bigger than maximum val
        }
        return (s_idx) ? s_idx - e_idx + 1 : 0;
    }
};

int main() {}