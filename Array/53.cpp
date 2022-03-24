#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {//O(N) Kadane's Algorithm O(N^2) -> O(N)
public://Subarry max 
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0];
        vector<int> arr(size,0);
        arr[0] = nums[0];
        int answer = nums[0];
        for(int i=1;i<size;++i){
            arr[i] = max(nums[i],arr[i-1] + nums[i]);//reset start line
            answer = max(answer,arr[i]);//end line
        }
        return answer;
    }
};

int main(){}