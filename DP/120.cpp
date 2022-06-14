#include <iostream>
#include <string.h>
#include <vector>
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {//Using DP
        int dp[201][201];
        memset(dp,0,sizeof(dp));
        dp[0][0] = triangle[0][0];
        int ans = INT_MAX;
        for(int i=1;i<triangle.size();++i){
            for(int j=0;j<triangle[i].size();++j){
                if(j == 0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }
                else if(j == triangle[i].size() - 1){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }
                else dp[i][j] = min(dp[i-1][j-1],dp[i-1][j]) + triangle[i][j];
            }
        }
        for(int i=0;i<triangle.size();++i){
            ans = min(ans,dp[triangle.size() - 1][i]);
        }
        return ans;
    }
};

int main(){}
