#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    int N;
    int M;
    int DFS(vector<vector<int>> &arr, vector<vector<bool>> &check, int x, int y){
        if() return 1;
        DFS(arr,check,x+1,y);
        DFS(arr,check,x,y+1);
        DFS(arr,check,x-1,y);
        DFS(arr,check,x,y-1);

    }
    int BFS(vector<vector<int>>& arr,vector<vector<bool>>&check,int x,int y){
        N = arr.size();
        M = arr[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> confirm;
        int ret = 1;
        check[x][y] = true;
        q.push({x, y});
        while(!q.empty()){
            int curx = q.front().first;
            int curt = q.front().second;
            for(int i = 0;i<4;++i){
                int nx = curx + dx[i];
                int ny = cury + dy[i];
                if(nx < 0 || ny < 0 || nx>=n || ny>=m || arr[curx][cury] >= arr[nx][ny] ||check[nx][ny]) continue;
                check[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    int longestIncreasingPath(vector<vector<int>> &matrix){
        N = matrix.size();
        M = matrix[0].size();
        vector<vector<bool>> check(n, vector<bool>(m, false));
        int ans = 1;
        for (int i = 0; i < n; ++i){
            for(int j=0;j<m;++j){
                if(check[i][j]) continue;
                ans = max(ans, BFS(matrix, check, i, j));
            }
        }
    }
};

int main() {}