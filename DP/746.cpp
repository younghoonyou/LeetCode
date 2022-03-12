#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {// O(N)
        int size = cost.size();
        if(size == 2) return min(cost[0],cost[1]);
        int dp[size];
        dp[0] = cost[0] , dp[1] = cost[1];
        for(int i=2;i<size;++i){
            dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
        }
        return min(dp[size - 1],dp[size - 2]);
    }
};//Using Dynamic Programming

int main(){
    Solution s;
    vector<int> temp = {
        10,15,20
    };

    cout<<s.minCostClimbingStairs(temp);
    return 0;
}