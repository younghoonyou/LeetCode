#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {//O(N)
        priority_queue<int,vector<int>,less<int>> q;
        for(int i=0;i<nums.size();++i){
            q.push(nums[i]);
        }
        while(--k) q.pop();
        return q.top();
    }
};

int main(){}