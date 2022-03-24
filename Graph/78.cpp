#include <iostream>
#include <vector>
using namespace std;
class Solution {//O(N^2)
public:
    vector<vector<int> > answer;
    vector<int> temp;
    void DFS(int k,vector<int>& arr){
        for(int i=k;i<arr.size();++i){
            temp.push_back(arr[i]);
            answer.push_back(temp);
            DFS(i+1,arr);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        answer.push_back({});
        DFS(0,nums);
        return answer;   
    }
};

int main(){}