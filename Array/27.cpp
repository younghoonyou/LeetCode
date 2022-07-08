#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    int removeElement(vector<int> &nums, int val){
        int count = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == val){
                nums.erase(nums.begin() + i);
                i--;
                continue;
            }
            count++;
        }
        return count;
    }
};

int main() {}