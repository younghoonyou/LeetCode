#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    bool finish;
    int level;
    char data;
    Node *alpha[26];
    Node() : finish(false) , level(0) ,data('\0') {
        for(int i=0;i<26;++i) alpha[i] = nullptr;
    }
    void insert(int n,string str){
        if(str[n] == '\0'){
            finish = true;
            return ;
        }
        int key = str[n] - 'a';
        if(alpha[key] == nullptr) alpha[key] = new Node(),alpha[key]->data = str[n];
        alpha[key]->insert(n+1,str);//next char
    }
};
class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int N,M;
    vector<string> answer;
    vector<vector<bool> > check;
    vector<pair<int,int> > alphabat[26];
    string temp = "";
    void Find_word(Node* node,int x,int y,vector<vector<char> >& board){
        if(node->finish){
                temp+=node->data;
                answer.push_back(temp);
                temp.pop_back();
                return ;
        }
        for(int i=0;i<4;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M || node->alpha[board[nx][ny] - 'a'] == nullptr || check[nx][ny]) continue;
            temp+=node->data;
            check[nx][ny] = true;
            Find_word(node->alpha[board[nx][ny] - 'a'],nx,ny,board);
            check[nx][ny] = false;
            temp.pop_back();
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<bool> exist(26,false);
        N = board.size();
        M = board[0].size();
        check.resize(N,vector<bool>(M,false));
        int i,j,word_size = words.size();
        Node *root = new Node();
        for(auto i:words) root->insert(0,i);
        for(i=0;i<N;++i)
        for(j=0;j<M;++j)
            alphabat[board[i][j] - 'a'].push_back({i,j}),exist[board[i][j] - 'a'] = true;

        sort(words.begin(),words.end());
        
        for(i=0;i<word_size;++i){
            if(!exist[words[i][0] - 'a']) continue;
            if(!exist[words[i][words[i].length() - 1] - 'a']) continue;
            // if(root->alpha[words[i][0] - 'a'] == nullptr) continue;
            for(j=0;j<alphabat[words[i][0] - 'a'].size();++j){
                int x = alphabat[words[i][0] - 'a'][j].first;
                int y = alphabat[words[i][0] - 'a'][j].second;
                check[x][y] = true;
                Find_word(root->alpha[board[x][y]-'a'],x,y,board);
                check[x][y] = false;
            }
        }
        sort(answer.begin(),answer.end());
        answer.erase(unique(answer.begin(),answer.end()),answer.end());
        return answer;
    }
};

int main(){
    Solution s;
    vector<vector<char> > map = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> input = {
        "oath","pea","eat","rain","oeii","ernlfi"
        // "abcd"
        // "aa"
    };
    for(auto i:s.findWords(map,input)) cout<<i<<" ";
}//We should use Trie algorithm
//if i use DFS algorithm it occurs tiem limitation O(N*M)
//Trie algorithm O(N)
//Trie = Prefix tree,Digital search tree, Retrieval tree