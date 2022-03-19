#include <iostream>
#include <algorithm>
#include <string>
class Solution { // O(N) N = string length
public:
    bool backspaceCompare(string s, string t) {
        string s_r = "";
        string t_r = "";
        for(char ch:s){
            if(ch == '#'){
                if(s_r.length() == 0) continue;
                s_r.pop_back();
                continue;
            }
            s_r +=ch;
        }

        for(char ch:t){
            if(ch == '#'){
                if(t_r.length() == 0) continue;
                t_r.pop_back();
                continue;
            }
            t_r +=ch;
        }
        return s_r == t_r ? true:false;
    }
};
int main(){

}