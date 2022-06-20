#include <iostream>
#include <string>
#include <vector>

class Solution {
private:
    static bool cmp(string &a,string &b){
        return a.length() > b.length();
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        int ans = 0;
        sort(words.begin(),words.end(),cmp);
        unordered_map<string,int> hash;
        for(string s:words) hash[s]++;
        for(int i=0;i<words.size();++i){
            int len = words[i].length();
            if(hash[words[i]]) ans+=(len + 1);
            for(int j=len-1;j>=0;--j){
                string temp = words[i].substr(j,len-j);
                hash[temp] = 0;
            }
        }
        return ans;
    }
};

int main(){}
