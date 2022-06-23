#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
class Solution{
public:
    bool isSubsequence(string s, string t){
        if (s.length() == 0 && t.length() == 0) return true;
        if (t.length() == 0) return false;
        if (s.length() > t.length()) return false;
        int start_s = 0;
        int start_t = 0;
        while (start_t != t.length() && start_s != s.length()){
            if (s[start_s] == t[start_t]) start_s++;
            start_t++;
        }
        return (start_s == s.length());
    }
};
int main() {}