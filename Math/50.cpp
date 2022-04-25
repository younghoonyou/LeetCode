#include <iostream>
#include <algorithm>
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        if(x == -1) return (n&1) ? -1:1;
        if(n == 0 || x == 1) return 1;
        bool flag = false;
        bool x_flag = false;
        if(n<0) flag = true;
        if(x<0 && n&1) x_flag = true;
        x = abs(x);
        n = abs(n);
        double tmp = x;
        while(--n){
            if(flag && 1/x<0.00001) return 0;
            if(x<0.00001) return 0;
             x*=tmp;
        }
        if(x_flag) x = -x;
        return (flag) ? 1/x:x;
    }
};

int main() {}