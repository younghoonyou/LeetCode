#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
public:
    int longestConsecutive(vector<int> &nums){
        if(nums.size() == 0) return 0;
        sort(nums.begin(),nums.end());
        int tmp = nums[0];
        int ans = 1;
        int ret = 1;
        for(int x:nums){
            if(tmp == x) continue;
            if(x - 1 == tmp) ans++;
            else ans = 1;
            ret = max(ans,ret);
            tmp = x;
        }
        return ret;
    }
};

int main(){}
