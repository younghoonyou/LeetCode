#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution{
public:
    bool find132pattern(vector<int> &nums){
        int n = nums.size();
        vector<int> mins(n, 0);
        stack<int> s;
        mins[0] = nums[0];
        for (int i = 1; i < n; ++i) mins[i] = min(nums[i], mins[i - 1]);
        for (int j = n - 1; j > 0; j--){
            if (nums[j] > mins[j]){
                while (s.size() > 0 && s.top() <= mins[j]) s.pop();
                if (s.size() > 0 && s.top() < nums[j]) return true;
                s.push(nums[j]);
            }
        }
        return false;
    }
};

int main() {}