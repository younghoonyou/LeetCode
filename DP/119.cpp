#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{ // Pascal's theorem
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> hex(rowIndex+1,vector<int>(rowIndex+1,0));
        for(int i=0;i<=rowIndex;++i){
            for(int j=0;j<=i;++j){
                if(j==0 || j== i){
                    hex[i][j] = 1;
                    continue;
                }
                hex[i][j] = hex[i-1][j-1] + hex[i-1][j];
            }
        }
        return hex[rowIndex];
    }
};

int main(){}