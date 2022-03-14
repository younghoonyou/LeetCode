#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return nums[0];
        if(size == 2) return max(nums[0],nums[1]);
        if(size == 3) return max(max(nums[0],nums[1]),nums[2]);
        vector<int> dp1(size,0);//Drop first house
        vector<int> dp2(size,0);//Drop second house
        dp1[0] = nums[0];
        dp1[1] = nums[0];//Don't drop second house so dp1[1] same as dp1[0]
        dp2[1] = nums[1];//Don't drop first house so dp2[0] is 0
        for(int i=2;i<size;++i){
            dp2[i] = max(dp2[i-2] + nums[i],dp2[i-1]);//cmp with before and -2 index value
            if(i == size -1) continue;//because first and end is adjacent
            dp1[i] = max(dp1[i-2] + nums[i],dp1[i-1]);
        }
        int answer = max(dp1[size-2],dp2[size-1]);//maximum
        return answer;
    }
};

int main(){
    
}