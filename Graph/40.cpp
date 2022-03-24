#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > answer;
    vector<int> temp;
    void DFS(int sum,int target,vector<int>& arr,int k){
        int data = -1;
        if(sum>target) return ;
        if(sum == target){
            answer.push_back(temp);
        }
        for(int i=k;i<arr.size();++i){
            if(data == arr[i]) continue;
            data = arr[i];
            temp.push_back(arr[i]);
            DFS(sum+arr[i],target,arr,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        DFS(0,target,candidates,0);
        return answer;
    }
};

int main(){}