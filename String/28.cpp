#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Solution {//Using Brute Force
public:
    int strStr(string haystack, string needle) {
        if(haystack.length() < needle.length()) return -1;
        for(int i=0;i<=haystack.length() - needle.length();++i){
            int cnt = 0;
            for(int j=0;j<needle.length();++j){
                if(haystack[i+j]==needle[j]) cnt++;
                else break;
            }
            if(cnt == needle.length()) return i;
        }
        return -1;
    }
};

int main(){}