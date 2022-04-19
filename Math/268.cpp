#include <iostream>
#include <algorithm>
using namespace std;
class Solution{
public:
    int missingNumber(vector<int> &nums){//Using sum Cal O(N) , O(1)
        int sum = 0;
        int n = nums.size();
        for (int x : nums)
            sum += x;
        return (n * (n + 1)) / 2 - sum;
    }
};

int main() {}