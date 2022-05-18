#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution{
public:
    int time;
    vector<int> VisitTime, MinTime;
    vector<bool> visit;
    vector<vector<int>> Critical;
    unordered_map<int, vector<int>> ans;//adj arr
    void DFS(int cur, int parent){
        visit[cur] = true;
        VisitTime[cur] = MinTime[cur] = time++;
        for (int child : ans[cur]){
            if (child == parent) continue;
            if (!visit[child]) DFS(child, cur);// current node become parent node
            MinTime[cur] = min(MinTime[cur], MinTime[child]);// update but critical doesn't match
            if (VisitTime[cur] < MinTime[child]) Critical.push_back({cur, child}); // cur->child
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections){
        time = 0;
        visit.resize(n,false),VisitTime.resize(n), MinTime.resize(n);
        for (auto arr : connections){ // Make adj arr
            ans[arr[0]].emplace_back(arr[1]);
            ans[arr[1]].emplace_back(arr[0]);
        }
        DFS(0,-1);
        return Critical;
    }
};

int main() {}