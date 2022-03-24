#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {//O(log(N)) binary search
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        int start = 0, end = size - 1;
        while(start<end){
            int mid = (start + end)/2;
            if(nums[mid + 1] > nums[mid]) start = mid + 1;
            else end = mid;
        }
        return end;
    }
};

int main(){}