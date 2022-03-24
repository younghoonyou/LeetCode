#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {//reverse BFS marking with 'P' that is not possible
public://BFS search with boarder
    void Search(int x,int y,int n,int m,vector<vector<char> >& arr){
        const int dx[4] = {1,0,-1,0};
        const int dy[4] = {0,1,0,-1};
        queue<pair<int,int> > q;
        q.push({x,y});
        arr[x][y] = 'P';
        while(!q.empty()){
            int curx = q.front().first;
            int cury = q.front().second;
            q.pop();
            for(int i=0;i<4;++i){
                int nx = curx + dx[i];
                int ny = cury + dy[i];
                if(nx<0 || ny<0 || nx>=n || ny>=m || arr[nx][ny] =='P' || arr[nx][ny] == 'X') continue;
                arr[nx][ny] = 'P';
                q.push({nx,ny});
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int N = board.size();
        int M = board[0].size();
        if(N == 1 && M == 1) return ;
        for(int i=0;i<M;++i){
            if(board[0][i]=='O') Search(0,i,N,M,board);
        }
        for(int i=0;i<M;++i){
            if(board[N-1][i]=='O') Search(N-1,i,N,M,board);
        }
        for(int i=0;i<N;++i){
            if(board[i][0]=='O') Search(i,0,N,M,board);
        }
        for(int i=0;i<N;++i){
            if(board[i][M-1]=='O') Search(i,M-1,N,M,board);
        }
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                if(board[i][j] =='P') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};



class Solution {//BFS search O(N*M) + backup time
public:
    void Search(int x,int y,int n,int m,vector<vector<char> >& arr){
        const int dx[4] = {1,0,-1,0};
        const int dy[4] = {0,1,0,-1};
        int cnt = 0;
        arr[x][y] = 'X';
        bool flag = false;
        queue<pair<int,int> > q;
        vector<pair<int,int> > temp;
        temp.push_back({x,y});
        q.push({x,y});
        while(!q.empty()){
            int curx = q.front().first;
            int cury = q.front().second;
            q.pop();
            for(int i=0;i<4;++i){
                int nx = curx + dx[i];
                int ny = cury + dy[i];
                if(arr[nx][ny] == 'X') continue;
                if(nx==0 || ny==0 || nx==n-1 || ny==m-1){
                    if(arr[nx][ny] == 'O'){
                        flag = true;
                        break;
                    }
                    continue;
                }
                q.push({nx,ny});
                arr[nx][ny] = 'X';
                temp.push_back({nx,ny});
            }
            if(flag) break;
        }
            if(flag){
            for(auto i:temp){
                int xx = i.first;
                int yy = i.second;
                arr[xx][yy] = 'O';
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int N = board.size();
        int M = board[0].size();
        if(N == 1 && M == 1) return ;
        for(int i=1;i<N-1;++i){
            for(int j=1;j<M-1;++j){
                if(board[i][j] == 'O') Search(i,j,N,M,board);
            }
        }
    }
};

int main(){}