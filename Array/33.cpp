#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {//O(log N)
public:

    int stand_pivot(vector<int>& arr) {//연속적으로 올라가는 교차점 찾기
        int size = arr.size();
        int standard = arr[size-1];
        int start=0;
        int end=size - 1;
        while(start<end){
            int mid = (start+end)/2;
            if(arr[mid] > standard) start = mid + 1;
            else end = mid;
        }
        return start;
    }

    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size == 1){
            return target != nums[0] ? -1 : 0;
        }
        int left,right;
        int pivot = stand_pivot(nums);
        if(target == nums[pivot]) return pivot;
        if(target >= nums[pivot] && target<=nums[size-1]){//시작지점과 끝의 사이
            left = pivot;
            right = size - 1;
            while(left<=right){//form 알기
                int mid = (left + right)/2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] < target) left = mid + 1;
                else right = mid - 1;
            }
        }
        else{//위의 반대 지점
            left = 0;
            right = pivot-1;
            while(left<=right){
                int mid = (left + right)/2;
                if(nums[mid] == target) return mid;
                else if(nums[mid] < target) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> temp = {
        // 4,5,6,7,0,1,2
        1,3,5

    };
    Solution s;
    cout<<s.search(temp,5);
    return 0;
}