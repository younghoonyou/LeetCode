#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs){
        if (strs.size() == 1) return {{strs[0]}};
        vector<vector<string>> ans;
        unordered_map<string, int> map;
        int idx = 1;
        for (string s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            if (map[temp]){
                ans[map[temp] - 1].push_back(s);
                continue;
            }
            map[temp] = idx++;
            if (ans.size() < idx) ans.push_back({});
            ans[map[temp] - 1].push_back(s);
        }
        return ans;
    }
};

int main() {}