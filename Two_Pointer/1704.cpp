#include <iostream>
#include <algorithm>
class Solution {
public:
    bool halvesAreAlike(string s) {
        int start = 0;
        int end = s.length() - 1;
        int first,second;
        first = second = 0;
        while(start < end){
            char st = tolower(s[start]);
            char en = tolower(s[end]);
            if(st == 'a' || st == 'e'||st == 'i'||st == 'o'||st == 'u'){
               first++; 
            }
            if(en == 'a' || en == 'e'||en == 'i'||en == 'o'||en == 'u'){
                second++;
            }
            start++;
            end--;
        }
        return first == second;
    }
};

int main() {}