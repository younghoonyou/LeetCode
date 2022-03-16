#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int N = matrix.size();
        int M = matrix[0].size();
        if(N==1 && M==1) return matrix[0][0] == target ? true : false;
        int N_start = 0,N_end = N - 1;
        while(N_start<=N_end){
            int N_mid = (N_start + N_end)/2;
            if(matrix[N_mid][0] == target) return true;
            else if(matrix[N_mid][0] > target) N_end = N_mid - 1;
            else N_start = N_mid + 1;
        }
        int start = 0,end = M - 1;
        while(start<=end){
            int mid = (start + end)/2;
            if(matrix[N_end][mid] == target) return true;
            else if(matrix[N_end][mid] > target) end = mid - 1;
            else start = mid + 1;
        }
        return false;
    }
};//O(log(N)^2)     another answer : (bool) binary_search(matrix[].begin(),matrix[].end(),target)

int main(){
    
}