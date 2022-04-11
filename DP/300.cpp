#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return 1;
        int i,j,answer=1;
        vector<int>dp(size,1);
        for(i=0;i<size;++i){
            for(j=i;j<size;++j){
                if(nums[i] < nums[j]) dp[j] = max(dp[j],dp[i] + 1);
            }
            if(answer < dp[i]) answer = dp[i];
        }
        return answer;
    }
};//Longest Int Subsequence


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return 1;
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            } else {
                int tmp = 0;
                while(sub[tmp] < x) tmp++;
                sub[tmp] = x;
            }
        }
        return sub.size();
    }
};//Update with lower_bound

int main(){
    
    return 0;
}