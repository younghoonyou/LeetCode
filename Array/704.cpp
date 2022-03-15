#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0,end = nums.size() - 1;
        while(start<=end){
            int mid = (start + end)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        return -1;
    }
};//Binary Search O(log(N))

int main(){
    
}