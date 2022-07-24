#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    bool isCorrect(string s){
        if (stoi(s) <= 26 && stoi(s) > 0) return true;
        return false;
    }
    void Search(string s,vector<int>& dp, int &cnt){
        if (s[0] == '0') return;
        if (s.length() == 1 || s.length() == 0){
            cnt++;
            return;
        }
        if (isCorrect(s.substr(0, 1)))
            // cnt++;
        Search(s.substr(1), cnt);
        if (isCorrect(s.substr(0, 2)))
            Search(s.substr(2), cnt);
    }
    int numDecodings(string s){
        if (s[0] == '0') return 0;
        int cnt = 0;
        vector<int> dp(s.length());
        Search(s,dp,cnt);
        return cnt;
    }
};
int main() {}