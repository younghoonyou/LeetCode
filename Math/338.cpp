#include <iostream>
#include <algorithm>
using namespace std;

class Solution{//O(N)
public:
    vector<int> countBits(int n){
        vector<int> arr(n + 1, 0);
        for (int i = 1; i <= n; ++i){
            arr[i] = arr[(i >> 1)] + (i & 1);//Using shift operator and if i is odd + 1
        }
        return arr;
    }
};

class Solution{//O(N*M)
public:
    int num(int n){
        int i=0;
        while(n) n /= 2,i++;
        return i;
    }
    vector<int> countBits(int n){
        vector<int> ans(n+1,0);
        for (int i = 0; i <= n; ++i){
            int tmp = num(i);
            for(int j=0;j<=tmp;++j){
                if(i&(1<<j)) ans[i]++;
            }
        }
        return ans;
    }
};

int main() {}