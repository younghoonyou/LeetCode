#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {//Using BFS O(N)
public:
    int Search(int x,int n,vector<bool>& check,vector<vector<int>>& arr){
        queue<int> q;
        q.push(x);
        while(!q.empty()){
            int curx = q.front();
            q.pop();
            for(int i=0;i<n;++i){
                if(check[i] || x == i) continue;
                check[i] = true;
                q.push(i);
            }
        }
        return 1;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int answer = 0;
        int size = isConnected.size(),i,j;
        vector<bool> check(size,false);
        for(i=0;i<size;++i){
            if(check[i]) continue;
            check[i] = true;
            answer+=Search(i,size,check,isConnected);
        }
        return answer;
    }
};

int main(){}