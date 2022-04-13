#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {//
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans; 
        unordered_map<int,int> map;// map[x] = y // x counted yth
        for(int x:nums){
            map[x]++;
        }
        priority_queue<pair<int,int>> pq;//
        for(auto it = map.begin();it!=map.end();it++){
            pq.push({it->second,it->first});
        }
        while(!pq.empty() && k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

int main(){
    
}