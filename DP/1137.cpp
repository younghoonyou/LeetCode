#include <iostream>
using namespace std;
class Solution{
public:
    int dp[38];
    int tribonacci(int n){
        if (dp[n]) return dp[n];
        if (n == 0){
            dp[n] = 0;
            return dp[n];
        }
        else if (n == 1 || n == 2){
            dp[n] = 1;
            return dp[n];
        }
        else if (n == 3){
            dp[n] = 2;
            return dp[n];
        }
        return dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};
int main() {}