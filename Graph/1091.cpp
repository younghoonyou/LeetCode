#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {//Using BFS with Queue O(N*M)
public:
    const int dx[8] = {-1,-1,0,1,1,1,0,-1};
    const int dy[8] = {0,1,1,1,0,-1,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int size = grid.size();
        if(grid[0][0] == 1 || grid[size-1][size-1] == 1) return -1;
        queue<pair<int,int> > q;
        q.push({0,0});
        grid[0][0] = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<8;++i){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0 || ny<0 || nx>=size || ny>=size || grid[nx][ny] > 0) continue;
                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx,ny});
            }
        }
        return (grid[size-1][size-1]?grid[size-1][size-1]:-1);
    }
};

int main(){
    
}