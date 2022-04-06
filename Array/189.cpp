#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void left_rotate(vector<int>& arr,int k){
        int size = arr.size();
        vector<int> temp(k);
        for(int i = 0;i<k;++i) temp[i] = arr[i];
        arr.erase(arr.begin(),arr.begin() + k);
        arr.insert(arr.end(),temp.begin(),temp.end());
    }
    void right_rotate(vector<int>& arr,int k){
        int size = arr.size();
        vector<int> temp(k);
        for(int i = 0;i<k;++i) temp[i] = arr[size -k + i];
        while(k--) arr.pop_back();
        arr.insert(arr.begin(),temp.begin(),temp.end());
    }
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if(size == 1) return ;
        if(size < k){
            right_rotate(nums,k%size);
            return ;
        }
            if(size/2 < k) left_rotate(nums,size - k);
            else right_rotate(nums,k);
    }
};

int main(){}