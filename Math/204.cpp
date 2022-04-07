#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if(n<3) return 0;
        vector<bool> arr(n+1,false);
        int cnt = 0;
        for(int i=2;i<n;++i){
            if(arr[i]) continue;
            cnt++;
            for(int j=i*1;j<=n;j+=i){
                if(arr[j]) continue;
                arr[j] = true;
            }
        }
        return cnt;
    }
};

int main(){}