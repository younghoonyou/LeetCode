#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
class Solution{
public:
    int longestPalindrome(string s){
        if (s.length() == 1) return 1;
        unordered_map<char, int> hash;
        for (char ch : s) hash[ch]++;
        int ext = 0;
        int ans = 0;
        for (auto m : hash){
            if (m.second > 1){
                if (m.second & 1) ext = 1;
                ans += m.second / 2;
            }
            else ext = 1;
        }
        return (ext) ? ans * 2 + 1 : ans * 2;
    }
};
int main() {}