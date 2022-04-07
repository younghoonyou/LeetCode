#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#define MAX 100000
using namespace std;

class Solution {
public:
    bool iscycle(vector<int> adj[],vector<int> &vis,int id){
        if(vis[id]==1)
            return true;
        if(vis[id]==0){
            vis[id]=1;
            for(auto edge : adj[id]){
                if(iscycle(adj,vis,edge))
                    return true;
            }
        }
        vis[id] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(auto edge : pre)
            adj[edge[1]].push_back(edge[0]);
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(iscycle(adj,vis,i))
                return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<vector<int>> temp = {
        {1,0},
        {0,1},
        // {1,4},
        // {2,4},
        // {3,1},
        // {3,2},
        // {}
        // 20
    // {0,10},{3,18},{5,5},{6,11},{11,14},{13,1},{15,1},{17,4}
    };
    bool t = s.canFinish(2,temp);
    if(t){
        cout<<"Answer!!";
    }
    else cout<<"Error!!";
    return 0;
}