#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#define MAX 100000
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 1) return {0};
        vector<int> ans;
        vector<int> adj[numCourses];
        vector<int> cnt(numCourses,0);
        for(auto edge:prerequisites){
            adj[edge[1]].push_back(edge[0]);
            cnt[edge[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;++i){
            if(cnt[i] == 0) q.push(i);//which dose not need to take any course
        }
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(int i=0;i<adj[cur].size();++i){
                cnt[adj[cur][i]]--;//
                if(cnt[adj[cur][i]] == 0) q.push(adj[cur][i]);
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};

int main(){}