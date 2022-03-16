#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> answer;
        if(nums.size() == 0) return {-1,-1};
        if(nums.size() == 1){
            if(nums[0] == target) return {0,0};
            return {-1,-1};
        }
        int start = 0;
        int end = nums.size() - 1;
        while(start<=end){
            int mid = (start + end)/2;
            if(nums[mid] == target){
                int up,down;//until Not to be target
                up = down = mid;
                while(up<nums.size() && nums[up] == target) up++;
                while(down>=0 && nums[down] == target) down--;
                if(mid != up) up--;
                if(mid != down) down++;
                return {down,up};
            }
            else if(nums[mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        if(answer.empty()) return {-1,-1};
        return answer;
    }
};//Binary Search O(log(N))

int main(){
    
}