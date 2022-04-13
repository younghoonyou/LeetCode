#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {//Using Divide and Conquer
public:
    int findDuplicate(vector<int>& nums) {
        int start = 1 , end = nums.size() - 1;
        while(start<end){
            int mid = (start + end)/2;
            int cnt = 0;
            for(int i=0;i<nums.size();++i){
                if(nums[i] <= mid) cnt++;
            }
            if(cnt > mid) end = mid;
            else start = mid + 1;
        }
        return end;
    }
};

int main(){
    
}