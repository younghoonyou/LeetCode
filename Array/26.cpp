#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {//Using Library
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        return nums.size();
    }
};

int main(){}