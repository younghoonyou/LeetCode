#include <iostream>
#include <string>

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size() - 1;
        int len = 0;
        
        for(int i = n; i>=0; i--){
            if(len>0 && s[i] == ' ') break;
            if(s[i] != ' ') len++;
        }
        return len;
    }
};

int main(){}
