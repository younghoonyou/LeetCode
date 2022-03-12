#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int dp[46] = {0,};
    int climbStairs(int n) {
        if(dp[n]) return dp[n];
        if(n==1) return dp[n] = 1;
        if(n==2) return dp[n] = 2;
        return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};//Using Dynamic Programming

int main(){
    
    return 0;
}