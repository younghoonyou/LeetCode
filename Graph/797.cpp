#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > answer;
    vector<int> temp;
    void Search(int n,int N,vector<vector<int>>& arr){
        if(n == N){
            answer.push_back(temp);
            return ;
        }
        for(int i=0;i<arr[n].size();++i){
            temp.push_back(arr[n][i]);
            Search(arr[n][i],N,arr);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int N = graph.size();
        temp.push_back(0);
        Search(0,N-1,graph);
        return answer;
    }
};

int main(){}