#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
public:
    bool condition(vector<vector<char>> &arr,int x,int y,int n){
        for(int i=x;i<x+n;++i){
            for (int j = y;j<y+n;++j){
                if(arr[i][j] == 0)
                    return false;
            }
        }
        return true;
    }
    int Search(int n,vector<vector<char>>& arr){
        int x = arr.size() - n + 1;//x axis
        int y = arr[0].size() - n + 1;//y axis
        for (int i = 0; i <= x; ++i){
            for (int j = 0;j<=y;++j){
                if (condition(arr,x,y,n)) return n * n;
            }
        }
        return ret;
    }
    int maximalSquare(vector<vector<char>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        for(int i=1;i<=max(n,m);++i){
            ans = max(ans,Search(i,matrix));
        }
        return ans;
    }
};

int main() {}