#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution//O(log(N)) but Space is not O(1)
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> map;
        int start = 0;
        int end = nums.size() - 1;
        int ans = 0;
        while (start < end)
        {
            map[nums[start]]++;
            map[nums[end]]++;
            if (map[ans] < max(map[nums[start]], map[nums[end]]))
            {
                if (map[ans] < map[nums[start]])
                    ans = nums[start];
                else
                    ans = nums[end];
            }
            start++;
            end--;
        }
        if (start == end)
        {
            map[nums[start]]++;
            if (map[ans] < map[nums[start]])
                ans = nums[start];
        }
        return ans;
    }
};

class Solution{ // Because Majority is over than n/2 so it will only remain Majority
public://find duplicate -> What is Majority?
    int majorityElement(vector<int> &nums){
        int cnt = 0, ans;
        for (int x : nums){//O(N)
            if (cnt == 0) ans = x;
            if (ans == x) cnt++;
            else cnt--;
        }
        return ans;
    }
};

int main() {}