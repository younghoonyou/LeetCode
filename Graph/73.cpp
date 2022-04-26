#include <iostream>
#include <vector>
using namespace std;
class Solution {//O(N*M)
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<pair<int, int>> arr;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0;i<n;++i){
            for (int j = 0;j<m;++j){
                if(matrix[i][j] == 0) arr.push_back({i, j});
            }
        }
        for(pair<int, int> val:arr){
            int x = val.first;
            int y = val.second;
            for (int k = 0;k<m;++k) matrix[x][k] = 0;
            for (int k = 0;k<n;++k) matrix[k][y] = 0;
        }
    }
};

int main() {}