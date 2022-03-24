#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > answer;
    vector<int> temp;
    void DFS(int n,int k,vector<int>& arr,vector<bool>& check){
        int data = 11;
        if(n == arr.size()){
            answer.push_back(temp);
        }
        for(int i=0;i<arr.size();++i){
            if(check[i]) continue;
            if(i>0 && data == arr[i]) continue;
            temp.push_back(arr[i]);
            check[i] = true;
            data = arr[i];
            DFS(n+1,i,arr,check);
            check[i] = false;
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int size = nums.size();
        if(size == 1) return {nums};
        vector<bool> check(size,false);
        sort(nums.begin(),nums.end());
        DFS(0,0,nums,check);
        return answer;
    }
};

int main(){}