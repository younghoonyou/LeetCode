#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int N,M;
    const int dx[4] = {1,0,-1,0};
    const int dy[4] = {0,1,0,-1};
    vector<pair<int,int> > alpha[26];
    vector<vector<bool> > check;
    vector<string> answer;
    void Find_word(int cnt,string word,int x,int y,vector<vector<char>>& board){
        if(word.length() == cnt){
            answer.push_back(word);
        }
        check[x][y] = true;
        for(int i=0;i<4;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx>=N || ny>=M || check[nx][ny] || word[cnt]!=board[nx][ny]) continue;
            Find_word(cnt+1,word,nx,ny,board);
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        N = board.size();
        M = board[0].size();
        int i,j,word_size = words.size();
        check.resize(N,vector<bool>(M,0));
        for(i=0;i<N;++i)
        for(j=0;j<M;++j)
            alpha[board[i][j]-'a'].push_back({i,j});
        
        for(i=0;i<word_size;++i){
            for(int k=0;k<N;++k)fill(check[k].begin(),check[k].end(),false);
            for(j=0;j<alpha[words[i][0] - 'a'].size();++j){
                int x = alpha[words[i][0] - 'a'][j].first;
                int y = alpha[words[i][0] - 'a'][j].second;
                Find_word(1,words[i],x,y,board);
            }
        }
        sort(answer.begin(),answer.end());
        answer.erase(unique(answer.begin(),answer.end()),answer.end());
        return answer;
    }
};

int main(){
    Solution s;
    vector<vector<char> > map = {{'a','a'}};
    vector<string> input = {
        // "oath","pea","eat","rain"
        // "abcd"
        "aa"
    };
    for(auto i:s.findWords(map,input)) cout<<i<<" ";
}