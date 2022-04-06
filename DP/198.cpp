#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int first = 0,second = 0;
        for(int i=0;i<nums.size();++i){
            if(i&1) second = max(second + nums[i],first);//cmp with dp[i+2] , dp[i+3]
            else first = max(first+nums[i],second);
        }
        return max(first,second);
    }
};

int main(){}