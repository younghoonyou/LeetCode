#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks){//O(N*log(N))
        int n = rocks.size();
        for (int i = 0; i < n; ++i) capacity[i] -= rocks[i];//O(N)
        int ans = 0;
        sort(capacity.begin(), capacity.end());//O(N*log(N))
        for (int i = 0; i < n; ++i){//O(N)
            ans += capacity[i]; 
            if (ans > additionalRocks) return i;
        }
        return n;
    }
};

int main() {}