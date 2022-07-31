#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k){
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++){
            if (hash.find(nums[i]) != hash.end() && abs(hash[nums[i]] - i) <= k) return true;
            hash[nums[i]] = i;
        }
        return false;
    }
};

int main() {}