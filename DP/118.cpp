#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {//Pascal's theorem
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ans(numRows);
        for(int i=0;i<ans.size();++i) ans[i].resize(i+1,0);
        for(int i=0;i<numRows;++i){
            ans[i][0] = 1;
            ans[i][i] = 1;
        }
        if(numRows < 3) return ans;
        for(int i=2;i<numRows;++i){
            for(int j=1;j<i;++j){
                ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
            }
        }
        return ans;
    }
};

int main(){}