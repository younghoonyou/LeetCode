#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {//Dynamic Programming But approach as Greedy method
public:
    void 
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int index = 0;
        for(int i=0;i<size;++i){
            if(i > index) return false;
            index = max(index,nums[i] + i);
        }
        return true;
    }
};

int main(){
    
    return 0;
}