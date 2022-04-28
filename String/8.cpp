#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    int myAtoi(string s){
        long ans = 0;
        int idx = 0;
        int flag = 1;//control pos/nega
        while (s[idx] == ' ') idx++;
        if (s[idx] == '+' || s[idx] == '-') flag = (s[idx] == '+') ? 1 : -1, idx++;
        while (isdigit(s[idx]) && idx < s.length()){
            ans = (ans * 10) + s[idx] - '0';
            if (ans * flag >= INT_MAX) return INT_MAX;
            if (ans * flag <= INT_MIN) return INT_MIN;
            idx++;
        }
        return flag * ans;
    }
};

int main() {}