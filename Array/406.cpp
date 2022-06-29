#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0] == b[0]) return a[1]<b[1];
        return a[0] > b[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(),people.end(),cmp);
        for(auto i:people){
            int idx = i[1];
            ans.insert(ans.begin() + idx,i);
        }
        return ans;
    }
};

int main() {}