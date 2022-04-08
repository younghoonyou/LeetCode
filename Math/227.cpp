#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long Cal(long a,long b,char ch){
        if(ch == '+') return a+b;
        else if(ch == '*') return a*b;
        else return a/b;
    }
    int calculate(string s) {
        stack<long> num;
        stack<char> oper;
        char tmp = ' ';
        for(int i=0;i<s.length();++i){
            if(s[i] == ' ') continue;
            if(isdigit(s[i])){
                if(isdigit(tmp)){
                    long a = num.top();
                    num.pop();
                    a = 10*a + s[i] - '0';
                    num.push(a);
                }
                else num.push(s[i] - '0');
            }
            else{
                if(s[i] == '*' || s[i] == '/' || s[i] == '-'){
                    string temp = "";
                    int j = i+1;
                    while(s[j] == ' ') ++j;
                    while(isdigit(s[j])){
                        temp+=s[j];
                        ++j;
                    }
                    long tmp = stoi(temp);
                    if(s[i] == '-'){
                        std::cout<<-tmp;
                        oper.push('+');
                        num.push(-tmp);
                        i = j - 1;
                        continue;
                    }
                    long a = num.top();
                    num.pop();
                    tmp = Cal(a,tmp,s[i]);
                    num.push(tmp);                    
                    if(j == s.length() - 1) break;
                    i = j - 1;
                }
                else oper.push(s[i]);
            }
            tmp = s[i];
        }
        int ans = 0;
        while(!num.empty()){
            ans+=num.top();
            num.pop();
        }
        return ans;
    }
};

int main(){}