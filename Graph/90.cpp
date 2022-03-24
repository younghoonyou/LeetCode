#include <iostream>
#include <vector>
using namespace std;
class Solution {//O(N^2)
public:
    vector<vector<int> > answer;
    vector<int> temp;
    void DFS(int k,vector<int>& arr){
        int data = 11;
        for(int i=k;i<arr.size();++i){
            if(data == arr[i]) continue;
            data = arr[i];
            temp.push_back(arr[i]);
            answer.push_back(temp);
            DFS(i+1,arr);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        answer.push_back({});
        DFS(0,nums);
        return answer;   
    }
};

int main(){}