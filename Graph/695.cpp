#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution{
public:
    int Search(vector<vector<int>> &grid, int x, int y){
        int ret = 1;
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        queue<pair<int, int>> q;
        q.push({x, y});
        grid[x][y] = 0;
        while (!q.empty()){
            int curx = q.front().first;
            int cury = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i){
                int nx = curx + dx[i];
                int ny = cury + dy[i];
                if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] == 0) continue;
                q.push({nx, ny});
                grid[nx][ny] = 0;
                ret++;
            }
        }
        return ret;
    }
    int maxAreaOfIsland(vector<vector<int>> &grid){
        int n = grid.size();
        int ans = 0;
        int m = grid[0].size();
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (grid[i][j] == 1) ans = max(ans, Search(grid, i, j));
            }
        }
        return ans;
    }
};

int main() {}