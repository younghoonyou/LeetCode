#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> map;
        vector<int> answer;
        if (nums1.size() > nums2.size())
        {
            for (int x : nums2)
            {
                map[x]++;
            }
            for (int x : nums1)
            {
                if (map[x])
                {
                    map[x]--;
                    answer.push_back(x);
                }
            }
        }
        else
        {
            for (int x : nums1)
            {
                map[x]++;
            }
            for (int x : nums2)
            {
                if (map[x])
                {
                    map[x]--;
                    answer.push_back(x);
                }
            }
        }
        return answer;
    }
};

int main(){}