#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    int DFS(vector<vector<int>> &arr, vector<vector<int>> &dp, int x, int y, int prev){
        if(x < 0 || y < 0 || x >= arr.size() || y >= arr[0].size() || arr[x][y] <= prev) return 0;
        if(dp[x][y]) return dp[x][y];
        int ret = 0;
        int left = DFS(arr,dp,x,y - 1,arr[x][y]);
        int right = DFS(arr,dp,x,y + 1,arr[x][y]);
        int down = DFS(arr, dp, x + 1,y,arr[x][y]);
        int up = DFS(arr, dp, x - 1,y,arr[x][y]);
        ret = max(max(left,right), max(down,up));
        return dp[x][y] = ret + 1;
    }
    int longestIncreasingPath(vector<vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 1;
        for (int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int temp = DFS(matrix, dp, i, j, -1);
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};

int main() {}