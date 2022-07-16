#include <iostream>
#include <string.h>

class Solution {
private:
    long int mod = 1e9+7;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int dp[55][55][55];
    bool flag = true;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if(flag){
            memset(dp,-1,sizeof(dp));
            flag = false;
        }
        if(startRow < 0 || startRow == m || startColumn < 0 || startColumn == n) return 1;
        if(maxMove <= 0) return 0;
        if(dp[startRow][startColumn][maxMove] != -1) return dp[startRow][startColumn][maxMove];
        long ans = 0;
        for(int i=0;i<4;++i){
            ans+=findPaths(m,n,maxMove - 1,startRow + dx[i],startColumn + dy[i])%mod;
        }
         return dp[startRow][startColumn][maxMove] = ans % mod;
    }
};

int main(){}
