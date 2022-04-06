#include <iostream>
#include <algorithm>
class Solution {
public:
    int five_cnt(int n){
        int i=0;
        while(n%5 == 0) n/=5,i++;
        return i;
    }
    int two_cnt(int n){
        int i=0;
        while(n%2 == 0) n/=2,i++;
        return i;
    }
    int trailingZeroes(int n) {
        int five = 0,two = 0;
        while(n){
            if(n%5 == 0) five+=five_cnt(n);
            if(n%2 == 0) two+=two_cnt(n);
            n--;
        }
        return min(five,two);
    }
};

int main(){}