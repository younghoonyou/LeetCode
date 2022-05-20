#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{//Using DP Math
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid){
        if (obstacleGrid[0][0]) return 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> check(n, vector<int>(m, 0));
        if (n == 1 && m == 1) return 1;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (obstacleGrid[i][j]) continue;
                if (i == 0 && j == 0) check[i][j] = 1;
                else if (i == 0) check[i][j] = check[i][j - 1];
                else if (j == 0) check[i][j] = check[i - 1][j];
                else check[i][j] = check[i - 1][j] + check[i][j - 1];
            }
        }
        return check[n - 1][m - 1];
    }
};

int main() {}