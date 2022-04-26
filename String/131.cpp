#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution{
public:
    bool isPalindorme(string &s, int start, int end){//Identifiy is that Palindorme
        if (s.length() == 1) return true;
        while (start < end){
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(vector<vector<string>> &ans, vector<string> &tmp, string &s, int i){
        if (i == s.length()){//
            ans.push_back(tmp);
        }
        for (int j = i; j < s.size(); ++j){
            if (isPalindorme(s, i, j)){
                tmp.push_back(s.substr(i, j - i + 1));//interval i~j
                solve(ans, tmp, s, j + 1);//start next index j+1
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s){
        if (s.length() == 0) return {{""}};
        else if (s.length() == 1) return {{s}};
        vector<vector<string>> answer;
        vector<string> temp;
        solve(answer, temp, s, 0);
        return answer;
    }
};

int main() {}