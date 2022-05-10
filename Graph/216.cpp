#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int num[10] = {0,1,2,3,4,5,6,7,8,9};
    void Search(vector<vector<int>>& arr,vector<int> &temp,int target,int sum,int k,int s){
        if(sum == target && temp.size() == s){
            arr.push_back(temp);
            return ;
        }
        for(int i=k;i<10;++i){
            temp.push_back(num[i]);
            Search(arr,temp,target,sum+num[i],i+1,s);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        vector<int> temp;
        Search(ans,temp,n,0,1,k);
        return ans;
    }
};

int main(){}
