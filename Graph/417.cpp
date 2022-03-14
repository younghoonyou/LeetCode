#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    const int dx[4] = {1,0,-1,0};
    const int dy[4] = {0,1,0,-1};
    void BFS(int x,int y,int n,int m,vector<vector<int>>& arr,vector<vector<bool> >&check){
        queue<pair<int,int> > q;
        q.push({x,y});
        check[x][y] = true;
        while(!q.empty()){
            int curx = q.front().first;
            int cury = q.front().second;
            q.pop();
            for(int i=0;i<4;++i){
                int nx = curx + dx[i];
                int ny = cury + dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m || check[nx][ny] || arr[nx][ny] < arr[curx][cury]) continue;
                q.push({nx,ny});
                check[nx][ny] = true;
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) { 
        vector<vector<int> > land;
        int N = heights.size();
        int M = heights[0].size();
        vector<vector<int> > answer;
        if(N==1&&M==1){
            answer.push_back({0,0});
            return answer;
        }
        int i,j;
        if(N == 1){
            for(i=0;i<M;++i) answer.push_back({0,i});
            return answer;
        }
        if(M == 1){
            for(i=0;i<N;++i) answer.push_back({i,0});
            return answer;
        }
        vector<vector<bool> > Pacific(N,vector<bool>(M,false));
        vector<vector<bool> > Atlantic(N,vector<bool>(M,false));
        for(i=0;i<M;++i){//Up
            if(Pacific[0][i]) continue;
            BFS(0,i,N,M,heights,Pacific);
        }
        for(i=0;i<N;++i){//Left
            if(Pacific[i][0]) continue;
            BFS(i,0,N,M,heights,Pacific);
        }
        for(i=0;i<M;++i){//Down
            if(Atlantic[N-1][i]) continue;
            BFS(N-1,i,N,M,heights,Atlantic);
        }
        for(i=0;i<N;++i){//Right
            if(Atlantic[i][M-1]) continue;
            BFS(i,M-1,N,M,heights,Atlantic);
        }

        for(i=0;i<N;++i){
            for(j=0;j<M;++j){
                if(Pacific[i][j] & Atlantic[i][j]) answer.push_back({i,j});
            }
        }
        return answer;
    }
};

int main(){
    Solution s;
    vector<vector<int> > temp = {
        {1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}
    };
    for(auto i:s.pacificAtlantic(temp)){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<'\n';
    }
}