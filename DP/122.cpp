#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution//Using DP low to high because of MAX return
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; ++i)
        {
            int tmp;
            if (prices[i] < prices[i - 1])
                tmp = 0;
            else
                tmp = prices[i] - prices[i - 1];
            dp[i] = max(dp[i], dp[i - 1] + tmp);
        }
        return dp[n - 1];
    }
};

int main() {}