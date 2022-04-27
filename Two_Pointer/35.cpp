#include <iostream>
#include <algorithm>
class Solution//O(logN)
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size() - 1;
        if (nums[end] < target)
            return nums.size();
        if (nums[start] > target)
            return start;
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] > target)
                end--;
            else if (nums[mid] < target)
                start++;
            else
                return mid;
        }
        return start;
    }
};

int main() {}