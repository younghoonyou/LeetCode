#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Solution{
public:
    bool Palindrome(string s,int start,int end){
        while(start < end){
            if(s[start] != s[end]) return false;
            start++, end--;
        }
        return true;
    }
    bool validPalindrome(string s){
        int start = 0;
        int end = s.length() - 1;
        while(start < end){
            if(s[start] != s[end]) return Palindrome(s, start + 1, end) || Palindrome(s, start, end - 1);
            //when start is deleted , when end is deleted
        }
    }
};
int main() {}