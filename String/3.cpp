#include <iostream>
using namespace std;

class Solution//O(N^2) Solution But Fast than O(N) because of DP
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        bool arr[95];
        for (int i = 0; i < s.length(); ++i)
        {
            memset(arr, false, sizeof(arr));
            int cnt = 0;
            for (int j = i; j < s.length(); ++j)
            {
                if (arr[(int)s[j] - 32])
                    break;
                arr[(int)s[j] - 32] = true;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

class Solution//O(N)
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, bool> map;
        int i, j, n = s.length(), ans;
        i = j = ans = 0;
        while (i < n && j < n)
        {
            if (map[s[j]])
                map.erase(s[i++]);
            else
            {
                map[s[j++]] = true;
                ans = max(ans, j - i);
            }
        }
        return ans;
    }
};

int main() {}