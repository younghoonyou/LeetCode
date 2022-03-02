//https://leetcode.com/problems/remove-duplicate-letters/
class Solution {
public:
    string removeDuplicateLetters(string s){
    string ans="";
    bool alpha[26] = {false,};
    int cnt[26] = {0,};
    for(char ch:s) cnt[ch-'a']++;//개수 추가
    for(char ch:s){
        cnt[ch-'a']--;//개수 감소
        if(ans.empty()){//첫번째면
            ans+=ch;
            alpha[ch-'a'] = true;
            continue;
        }
        if(alpha[ch-'a']) continue;//확인되면 패스
        while(!ans.empty() && cnt[ans.back()-'a']>0 && ans.back()>ch){//
            alpha[ans.back()-'a'] = false;//나중에 추가하려고
            ans.pop_back();//뒤에 제거
        }
        alpha[ch-'a'] = true;
        ans+=ch;
    }
    return ans;
    }
};