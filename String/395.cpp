#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
class Solution{//Using hash , Recursion
public:
    int longestSubstring(string s, int k){
        if (s.length() < k) return 0;
        if (k == 1) return s.length();
        unordered_map<char, int> map;
        for (char ch : s) map[ch]++;
        int i;
        for (i = 0; map[s[i]] >= k; ++i) {}
        if (i == s.length()) return s.length();
        int left = longestSubstring(s.substr(0, i), k);//divide
        int right = longestSubstring(s.substr(i + 1), k);
        return max(left, right);
    }
}; // reference : https://strange-developer.tistory.com/60
int main() {}