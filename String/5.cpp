#include <iostream>
#include <string>
using namespace std;
class Solution{
public:
    string ss;
    bool isPalindrome(int start, int end){
        if (start > end) return false;
        while (start < end){
            if (ss[start] != ss[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s){
        int len = s.length();
        if (len == 0) return "";
        if (len == 1) return s;
        int longlen = 0;
        ss = s;
        string maxstring = "";
        for (int i = 0; i < len; ++i){
            for (int j = i; j < len; ++j){
                if (j - i + 1 > longlen && isPalindrome(i, j)){
                    longlen = j - i + 1;
                    maxstring = s.substr(i, longlen);
                }
            }
        }
        return maxstring;
    }
};

int main() {}