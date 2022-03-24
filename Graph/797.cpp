#include <iostream>
#include <vector>
using namespace std;
class Solution {//Worst Case O(N^2)
public:
    void Search(int n,int N,vector<vector<int>>& arr,vector<vector<int> >& answer,
    vector<int>& temp){
        if(n == N){//condition
            answer.push_back(temp);
            return ;
        }
        for(int i=0;i<arr[n].size();++i){
            temp.push_back(arr[n][i]);
            Search(arr[n][i],N,arr,answer,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int> > answer;
        vector<int> temp;
        int N = graph.size();
        temp.push_back(0);
        Search(0,N-1,graph,answer,temp);
        return answer;
    }
};

int main(){}