#include <iostream>
#include <vector>
using namespace std;
char num[8][4] = {
            {'a','b','c',' '},//2   index 0
            {'d','e','f',' '},//3   index 1
            {'g','h','i',' '},//4   index 2
            {'j','k','l',' '},//5   index 3
            {'m','n','o',' '},//6   index 4
            {'p','q','r','s'},//7   index 5
            {'t','u','v',' '},//8   index 6
            {'w','x','y','z'},//9   index 7
        };
class Solution {
public:
    vector<string> answer;
    string temp = "";
    void combination(int n,string str){
        if(n==str.length()){
            answer.push_back(temp);
            return ;
        }
        for(int i=0;i<4;++i){
            if(num[str[n] - '0' -2][i] == ' ') continue;
            temp+=num[str[n] - '0' -2][i];
            combination(n+1,str);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(int n,string digits) {
        if(digits.length() == 0) return answer;
        combination(0,digits);
        return answer;
    }
};

int main(){
    Solution s;
    string str;
    cin>>str;
    for(auto i:s.letterCombinations(0,str)){
        cout<<i<<" ";
    }
    return 0;
}