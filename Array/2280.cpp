#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    int minimumLines(vector<vector<int>> &stockPrices){
        int n = stockPrices.size();
        if (n == 1) return 0;
        else if (n == 2) return 1;
        sort(stockPrices.begin(), stockPrices.end());
        for (int i = 1; i < n; ++i) stockPrices[i - 1][0] -= stockPrices[i][0], stockPrices[i - 1][1] -= stockPrices[i][1];
        stockPrices.pop_back();
        int ans = 1;
        for (int i = 1; i < n - 1; ++i){
            long x1 = stockPrices[i][0];
            long y1 = stockPrices[i][1];
            long x0 = stockPrices[i - 1][0];
            long y0 = stockPrices[i - 1][1];
            long long a = y0 * x1;
            long long b = x0 * y1;
            if (a != b) ans++;
        }
        return ans;
    }
};

int main() {}