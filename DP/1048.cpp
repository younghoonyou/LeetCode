#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
private:
    static bool cmp(string &a, string &b){
        return a.length() < b.length();
    }

public:
    int longestStrChain(vector<string> &words){//Using DP
        int ans = 0;
        int size = words.size();
        sort(words.begin(), words.end(), cmp);//Because its order
        unordered_map<string, int> hash;//Using hash
        for (string str : words){
            hash[str] = 1;
            for (int i = 0; i < str.length(); ++i){
                string temp = str.substr(0, i) + str.substr(i + 1); // except one word
                if (hash.find(temp) != hash.end()) hash[str] = max(hash[str], hash[temp] + 1);
                ans = max(ans, hash[str]);
            }
        }
        return ans;
    }
};

int main(){}