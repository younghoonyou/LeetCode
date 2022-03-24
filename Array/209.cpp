#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {//O(N) Two Pointer
        int size = nums.size();
        int start,end;
        if(size == 1) return 0;
        start = 0;
        end = 0;
        int answer = 100001;
        int sum = nums[start];
        while(start<=end){
            if(end==size-1 && start==size-1){
                if(target <=sum) answer = min(answer,end-start+1);
            }
            if(end==size-1){
                if(target <=sum) answer = min(answer,end-start+1);
                sum-=nums[start];
                start++;
                continue;
            }
            if(target > sum) end++,sum+=nums[end];
            if(target <= sum){
                answer = min(answer,end - start + 1);
                sum-=nums[start];
                start++;
            }
        }
        return answer == 100001 ? 0:answer;
    }
};
int main(){}