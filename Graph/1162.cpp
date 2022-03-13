#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    const int dx[4] = {1,0,-1,0};
    const int dy[4] = {0,1,0,-1};
    queue<pair<int,int> > q;
    int BFS(int n,vector<vector<int> >&arr){
        int dist = 0;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;++i){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=n || arr[nx][ny] > 0) continue;
                arr[nx][ny] = arr[x][y] + 1;
                q.push({nx,ny});
                dist = max(dist,arr[nx][ny]);
            }
        }
        return dist;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int size = grid.size(),i,j,water=0;
        vector<pair<int,int> > land;
        for(i=0;i<size;++i){
            for(j=0;j<size;++j){
                if(grid[i][j] == 1) q.push({i,j});
                else water++;
            }
        }
        if(!water || q.empty()) return -1;
        int answer = BFS(size,grid);
        return answer;
    }
};

int main(){
    
}