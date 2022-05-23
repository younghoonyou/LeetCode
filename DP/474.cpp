#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{//Kanpsack DP
public:
    int findMaxForm(vector<string> &strs, int m, int n){
        vector<vector<int>> arr(m + 1, vector<int>(n + 1, 0));//O(N*M)
        for (string s : strs){//O(S*M*N)
            int one, zero;
            one = zero = 0;
            for (char ch : s){ // one zero cnt
                if (ch == '0') zero++;
                else one++;
            }

            for (int i = m; i >= zero; --i){
                for (int j = n; j >= one; --j){
                    arr[i][j] = max(arr[i][j], arr[i - zero][j - one] + 1);
                }
            }
        }
        return arr[m][n];
    }
}; // Knapsack Dynamic Programming

int main() {}