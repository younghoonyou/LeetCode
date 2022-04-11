#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<pair<int,int> > live;
        vector<pair<int,int> > dead;
        const int dx[8] = {-1,-1,0,1,1,1,0,-1};
        const int dy[8] = {0,1,1,1,0,-1,-1,-1};
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                int cnt = 0;
                for(int k=0;k<8;++k){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx<0 || ny<0 || nx>=n || ny>=m || board[nx][ny] == 0) continue;
                    cnt++;
                }
                if(board[i][j] == 1 && (cnt<2 || cnt>3)) dead.push_back({i,j});
                if(board[i][j] == 0 && cnt==3) live.push_back({i,j});
            }
        }
        for(int i=0;i<live.size();++i){
            int x = live[i].first;
            int y = live[i].second;
            board[x][y] = 1;
        }
        for(int i=0;i<dead.size();++i){
            int x = dead[i].first;
            int y = dead[i].second;
            board[x][y] = 0;
        }
    }
};

int main(){}