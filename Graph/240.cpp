#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target){
        int N = matrix.size();
        int M = matrix[0].size();
        if (N == 0 || M == 0) return false;
        int start = 0;
        int end = M - 1;
        while (start < N && end >= 0){
            if (matrix[start][end] == target) return true;
            else if (matrix[start][end] < target) start++;
            else end--;
        }
        return false;
    }
};

int main(){}