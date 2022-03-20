#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        if(size<3) return {};
        vector<vector<int> > answer;
        sort(nums.begin(),nums.end());
        for(int i=0;i<size;++i){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int start = i+1,end = size - 1;
            while(start<end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum > 0) end--;
                else if(sum < 0) start++;
                else{
                  answer.push_back({nums[i],nums[start],nums[end]}),start++;  
                  while(nums[start] == nums[start-1] && start<end) start++;
                }
            }
        }
        return answer;
    }
};

int main(){
    
}//O(n*log(n)) one loop * binary search
//You should know two sum problem