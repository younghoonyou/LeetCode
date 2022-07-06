#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Solution{
private:
    static bool compare(pair<int, string> a, pair<int, string> b){
        if (a.first == b.first) return a.second < b.second;
        else return a.first > b.first;
    }
public:
    vector<string> topKFrequent(vector<string> &words, int k){
        map<string, int> m;
        for (string s : words) m[s]++;
        vector<pair<int, string>> vec;
        vector<string> ans;
        for (auto i : m) vec.push_back({i.second, i.first});
        sort(vec.begin(), vec.end(), compare);
        for (int i = 0; i < k; ++i) ans.push_back(vec[i].second);
        return ans;
    }
};
int main() {}