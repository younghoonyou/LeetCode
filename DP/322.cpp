#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int size = coins.size();
        if(size == 1) return amount%coins[0] == 0 ? amount/coins[0]:-1;
        vector<int> dp(amount + 1,987654321);
        dp[0] = 0;
        for(int i=1;i<=amount;++i){
            for(auto j:coins){
                if(j>i) continue;
                dp[i] = min(dp[i],dp[i-j] + 1);
            }
        }
        return (dp[amount] == 987654321) ? -1:dp[amount];
    }
};//Knapsack Dynamic Programming

int main(){
    
    return 0;
}