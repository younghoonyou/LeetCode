#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s){
        if(s.length() == 0) return 0;
        if(s.length() == 1) return 1;
        bool alpha[26] = {false,};//중복 확인
        int answer = 1;
        int arr[26];
        for(int i=0;i<s.length()-1;++i){
            if(!isalpha(s[i])) continue;
            int index = 0;
            int temp = 1;
            alpha[s[i]-'a'] = true;//확인 표시
            for(int j=i+1;j<s.length();++j){
                if(!isalpha(s[j])) continue;
                if(alpha[s[j]-'a']) break;
                alpha[s[j]-'a'] = true;
                arr[index++] = s[j]-'a';
                temp++;
                if(answer < temp) answer = temp;
            }
            for(int t=0;t<index;++t) arr[arr[t]] = 0,alpha[arr[t]] = false;//원상 복구
            alpha[s[i]-'a'] = false;//확인 제거
        }
        return answer;
    }
};

int main(){
    Solution s;
    string str;
    cin>>str;
    int ans = s.lengthOfLongestSubstring(str);
    cout<<ans;
    return 0;
}