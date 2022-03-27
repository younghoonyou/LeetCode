#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> temp;
    for(int i=0;i<nums.size()-1;++i){
        for(int j=i+1;j<=nums.size()-1;++j){
            int total = nums[i] + nums[j];
            if(total==target){
                temp.push_back(i);
                temp.push_back(j);
            }
        }
    }
        return temp;
    }
};

int main(){
}