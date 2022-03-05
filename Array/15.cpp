#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int> > answer;
    vector<int> temp;
    void DFS(int n,int sum,int k,vector<int>& arr){
        if(n == 3 && sum == 0){
            answer.push_back(temp);
            return ;
        }
        for(int i=k;i<arr.size();++i){
            temp.push_back(arr[i]);
            DFS(n+1,sum+arr[i],i+1,arr);
            temp.pop_back();
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();        
        if(size<3) return answer;
        DFS(0,0,0,nums);
        vector<int> store = {100001,100001,100001};
        sort(answer.begin(),answer.end());
        answer.erase(unique(answer.begin(),answer.end()),answer.end());
        return answer;
    }
};

int main(){
    vector<int> temp = {
        34,55,79,28,46,33,2,48,31,-3,84,71,52,-3,93,15,21,-43,57,-6,86,56,94,74,83,-14,28,-66,46,-49,62,-11,43,65,77,12,47,61,26,1,13,29,55,-82,76,26,15,-29,36,-29,10,-70,69,17,49
    };
    Solution s;
    vector<vector<int> > t = s.threeSum(temp);
    for(int i=0;i<t.size();++i){
        for(int j=0;j<t[i].size();++j){
            cout<<t[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}//Kadane Algorithm O(N)