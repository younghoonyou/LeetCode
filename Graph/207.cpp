#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#define MAX 100000
using namespace std;

class Solution {
public:
    bool iscycle(int id){
        if(vis[id]==1)
            return true;
        if(vis[id]==0){
            vis[id]=1;//방문처리 후
            for(int i=0;i<cnt[id];++i){
                if(iscycle(adj[id][i]))
                    return true;
            }
        }
        vis[id] = 2;//완전히 표시
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        for(int i=0;i<pre.size();++i){
            adj[pre[i][1]][cnt[pre[i][1]]] = pre[i][0];
            cnt[pre[i][1]]++;
        }
        for(int i=0;i<n;i++){
            if(iscycle(i))//싸이클이냐?   한쌍,방문벡터,num
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