#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution//Using Max, Min update pair O(N)
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());//O(nlog(n))
        vector<int> tmp = intervals[0];
        for (int i = 1; i < intervals.size(); ++i)//O(n)
        {
            if (tmp[1] >= intervals[i][0])
            {
                tmp[0] = min(tmp[0], intervals[i][0]);
                tmp[1] = max(tmp[1], intervals[i][1]);
                continue;
            }
            ans.push_back(tmp);
            tmp = intervals[i];
        }
        ans.push_back(tmp);
        return ans;
    }
};

int main() {}