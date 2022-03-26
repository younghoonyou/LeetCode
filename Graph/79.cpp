#include <iostream>
#include <vector>
using namespace std;
class Solution {//O(N*M)
public:
    bool flag = false;
    void Search(int x,int y,int n,int N,int M,string word,string temp,vector<vector<char>>& board,vector<vector<bool> >& check){
        check[x][y] = true;
        if(word.size() == n){
            if(word.compare(temp)==0) flag = true;
        }
        const int dx[4] = {0,1,0,-1};
        const int dy[4] = {1,0,-1,0};
        for(int i=0;i<4;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M || board[nx][ny] != word[n] || check[nx][ny]) continue;
            check[nx][ny] = true;
            Search(nx,ny,n+1,N,M,word,temp+board[nx][ny],board,check);
            check[nx][ny] = false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int N = board.size();
        int M = board[0].size();
        for(int i=0;i<N;++i)
        for(int j=0;j<M;++j)
            if(board[i][j] == word[0]){
                vector<vector<bool> > check(N,vector<bool>(M,false));
                string str = "";
                str+=word[0];
                Search(i,j,1,N,M,word,str,board,check);
                if(flag) return true;
            }
        return false;
    }
};