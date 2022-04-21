#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution//just count num
{
public:
    void sortColors(vector<int> &nums)
    {
        vector<int> cnt(3, 0);
        for (int x : nums)
        {
            cnt[x]++;
        }
        int j = 0;
        for (int i = 0; i < 3; ++i)
        {
            for (int tmp = cnt[i]; tmp; ++j, tmp--)
            {
                nums[j] = i;
            }
        }
    }
};

int main() {}