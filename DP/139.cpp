#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool Sure(string main,string sub){//LCS
        int sub_len = sub.length();
        int main_len = main.length();
        if(sub_len > main_len) return false;
        // int index = 0,cnt = 0;
        // while(main[index] != sub[0]) index++;
        // for(int i=0;i<sub_len;++i){
        //     if(main[i + index] == sub[i]) cnt++;
        // }
        // return cnt == sub_len ? true:false;
        int cnt = 0;

        for(int i=0;i<main_len;++i){
            if(main[i] == sub[0]){
                for(int j=0;j<sub_len;++j){
                    if(main[i + j] != sub[j]) break;
                    cnt++;
                }
                if(cnt == sub_len) return true;
                cnt = 0;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        bool ans = true;
        for(auto i:wordDict) ans &= Sure(s,i);
        return ans;
    }
};//LCS DP

int main(){
    
    return 0;
}