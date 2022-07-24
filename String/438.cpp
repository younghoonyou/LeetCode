#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
            vector<int> answer;
           int len = p.length();
           int s_len = s.length();
           int sum = 0;
           if(len > s_len) return answer;
           if(s_len == 1) return s[0] == p[0] ? {0}:answer;
           for(char ch:p) sum+= p - 'a';
           for(int i=0;i<=s_len - len;++i){
               int temp = 0;
               for(int j=i;j<i+len;++j) temp+= s - 'a';
               if(temp == sum){
                   answer.push_back(i);
               }
           }
        return answer;
    }
};
int main(){

}