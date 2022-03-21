#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {//using BFS O(N*M)
public:
    const int dx[4] = {1,0,-1,0};
    const int dy[4] = {0,1,0,-1};
    int Search(int x,int y,int n,int m,vector<vector<char>>& grid){
        queue<pair<int,int> > q;
        q.push({x,y});
        while(!q.empty()){
            int curx = q.front().first; 
            int cury = q.front().second;
            q.pop();
            for(int i=0;i<4;++i){
                int nx = curx + dx[i];
                int ny = cury + dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m || grid[nx][ny] == '0' || grid[nx][ny] == '2') continue;
                grid[nx][ny] = '2';
                q.push({nx,ny});
            }
        }
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int answer = 0;
        int N = grid.size();
        int M = grid[0].size(),i,j;
        for(i=0;i<N;++i)
        for(j=0;j<M;++j)
            if(grid[i][j] == '1') answer+=Search(i,j,N,M,grid);
        return answer;
    }
};

int main(){}