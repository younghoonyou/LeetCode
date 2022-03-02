#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {//two pointer
        int size = nums.size();
        if(size==1) return nums[0];
        int max_arr[size],min_arr[size];
        int answer,i,temp_max,temp_min;
        temp_max = temp_min = nums[0];
        max_arr[0] = min_arr[0] = nums[0];
        for(i=1;i<size;++i){//O(n) 가능
            max_arr[i] = max(nums[i],max(max_arr[i-1]*nums[i],min_arr[i-1]*nums[i]));//모든 수 곱 최대
            min_arr[i] = min(nums[i],min(min_arr[i-1]*nums[i],max_arr[i-1]*nums[i]));//모든 수 곱 최소
            temp_min = max(temp_min,min_arr[i]);//음수 포함 최대
            temp_max = max(temp_max,max_arr[i]);//최대 중에 최대  음수 상관 x
        }
        answer = max(temp_max,temp_min);
        return answer;
    }
};

int main(){
    vector<int> temp = {
        1,2,4,-6,-7,-2,5,3
    };
    Solution s;
    cout<<s.maxProduct(temp);
    return 0;
}//Kadane Algorithm O(N)