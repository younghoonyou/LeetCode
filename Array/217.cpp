#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {//O(N)
public:
    bool containsDuplicate(vector<int>& nums) {
        int temp = 100000001;
        sort(nums.begin(),nums.end());
        for(int i:nums){
            if(temp==i) return true;
            temp = i;
        }
        return false;
    }
};

int main(){}