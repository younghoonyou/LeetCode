#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    vector<int> buildArray(vector<int> &nums){
        vector<int> ans;
        for (int x : nums) ans.push_back(nums[x]);
        return ans;
    }
};

int main() {}