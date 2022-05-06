#include <iostream>
#include <algorithm>
#include <string>
class Solution{
public:
    string removeDuplicates(string s, int k){
        vector<pair<char, int>> q;
        string ans = "";
        for (char ch : s){
            if (q.empty()){
                q.push_back({ch, 1});
                continue;
            }
            if (q.back().first == ch){
                int tmp = q[q.size() - 1].second;
                q.push_back({ch, tmp + 1});
            }
            else{
                q.push_back({ch, 1});
                continue;
            }
            if (q[q.size() - 1].second == k){
                int cnt = k;
                while (cnt--) q.pop_back();
            }
        }
        for (int i = 0; i < q.size(); ++i) ans += q[i].first;
        return ans;
    }
};
int main() {}