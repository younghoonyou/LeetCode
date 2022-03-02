#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {//about O(N)
public:
    int findMin(vector<int>& nums) {
        int size = nums.size(),i,index = -1;
        for(i=1;i<size;++i){
            if(nums[i] < nums[i-1]){
                index = i;//find index
                break;//Not need to find
            }
        }
        return (index == -1) ?  nums[0] :  nums[index];
    }
};

int main(){
    vector<int> temp = {
        7,0,1,2,3,4,5,6
    };
    Solution s;
    cout<<s.findMin(temp);
    return 0;
}

//we can use Divde and conquer algorithm O(logN)

//class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int l = 0, r = nums.size() - 1;
//         while (l < r) {
//             int m = l + (r - l) / 2;
//             if (nums[m] > nums.back()) l = m + 1;
//             else r = m;
//         }
//         return nums[l];
//     }
// };