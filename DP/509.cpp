class Solution{
public:
    int dp[31];
    int fib(int n){
        if (dp[n]) return dp[n];
        if (n == 0){
            dp[n] = 0;
            return dp[n];
        }
        if (n == 1 || n == 2){
            dp[n] = 1;
            return dp[n];
        }
        return dp[n] = fib(n - 1) + fib(n - 2);
    }
};

int main() {}