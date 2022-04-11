#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool is_power(int n){
        int t = (int)sqrt(n);
        return t*t == n;
    }
    int numSquares(int n) {
        if(is_power(n)) return 1;
        vector<int> arr(n+1,987654321);
        arr[0] = 0;
        for(int i=1;i<=n;++i){
            int cnt = 1;
            while(cnt*cnt <= i){
                arr[i] = min(arr[i],arr[i-cnt*cnt] + 1);
                cnt++;
            }
        }
        return arr[n];
    }
};

int main(){}