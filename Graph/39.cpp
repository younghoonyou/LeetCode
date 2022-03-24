#include <iostream>
#include <vector>
using namespace std;
class Solution {//
public:
    vector<vector<int> > answer;
    vector<int> temp;
    void DFS(int sum,int target,vector<int>& arr,int k){
        if(sum > target) return ;
        if(sum == target){
            answer.push_back(temp);
        }
        for(int i=k;i<arr.size();++i){
            temp.push_back(arr[i]);
            DFS(sum+arr[i],target,arr,i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        DFS(0,target,candidates,0);
        return answer;
    }
};

int main(){}