#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        int zero_cnt = 0;
        int stand = 1;
        int zero_stand;
        int i,index;
        vector<int> answer(size,0);
        if(size==0) return answer;
        for(i=0;i<size;++i){
            if(nums[i]==0){
                zero_cnt++;
                index = i;
                continue;
            }
            stand*=nums[i];
        }
        if(zero_cnt>0){
            if(zero_cnt>1){//0 2개이상
                return answer;
            }
            else{//0 1개
                answer[index] = stand;
                return answer;
            }
        }
        else{//0 없으면
            for(i=0;i<size;++i){
                answer[i] = stand/nums[i];
            }
        }
        return answer;
    }
};

int main(){
    vector<int> temp = {
        // -1,1,0,-3,3
        1,2,3,4
    };
    Solution s;
    for(auto i:s.productExceptSelf(temp)) cout<<i<<" ";
    // cout<<0/-1;
    return 0;
}