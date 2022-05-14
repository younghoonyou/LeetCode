#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k){//O(N*log(N)) Dijkstra using Heap
        vector<pair<int, int>> arr[n + 1]; // vertex
        for (int i = 0; i < times.size(); ++i) arr[times[i][0]].emplace_back(times[i][1], times[i][2]);
        vector<int> cost(n + 1, INT_MAX);
        vector<bool> visit(n + 1, false);                                    // visit
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q; // Dijkstra
        q.emplace(0, k);
        cost[k] = 0; // self
        while (!q.empty()){
            pair<int, int> tmp = q.top();
            q.pop();
            if (visit[tmp.second]) continue;             // already visit
            visit[tmp.second] = true; // visit
            for (int i = 0; i < arr[tmp.second].size(); ++i){                                      //
                int x = arr[tmp.second][i].first;  // next
                int w = arr[tmp.second][i].second; // weight
                if (cost[x] > cost[tmp.second] + w){ // update cost
                    cost[x] = cost[tmp.second] + w;
                    q.emplace(cost[x], x);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < cost.size(); i++) ans = max(ans, cost[i]);
        if (ans == INT_MAX) return -1; // disconnected node
        return ans;
    }
};

int main() {}