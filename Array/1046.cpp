#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int s1 = pq.top(); 
            pq.pop();
            int s2 = pq.top(); 
            pq.pop();
        if (s1 - s2 > 0) pq.push(s1 - s2);
        }
    if(!pq.empty()) return pq.top();
    else return 0;
    }
};

int main(){}
