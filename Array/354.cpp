#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Solution{
public:
    bool cmp(vector<int>&a,vector<int>&b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>> &envelopes){
        sort(envelopes.begin(),envelopes.end());
        for (auto a : envelopes){
            std::cout << a[0] << ' ' << a[0]<<'\n';
        }
    }
};
int main() {}