#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{//LCS algorithm using DP
public:
    int minDistance(string word1, string word2){
        word1 = '0' + word1;
        word2 = '0' + word2;
        int size1 = word1.length();
        int size2 = word2.length();
        int dp[501][501];
        int ans = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i < size1; ++i){
            for (int j = 1;j<size2;++j){
                if (word1[i] == word2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                ans = max(ans, dp[i][j]);
            }
        }
        size1 -= ans;
        size2 -= ans;
        return size1 + size2 - 2;
    }
};

int main() {}