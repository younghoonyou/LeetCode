#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    int Cal(int num1,int num2 ,string op){
        if(op == "+") return num1 + num2;
        else if(op == "-") return num1 - num2;
        else if(op == "*") return num1*num2;
        return num1/num2;
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto i:tokens){
            if(isdigit(i[0]) || i.length() > 1){
                s.push(stoi(i));
                continue;
            }
            else{
                int second = s.top();
                    s.pop();
                int first = s.top();
                    s.pop();
                int temp = Cal(first,second,i);
                    s.push(temp);
                }
        }
        return s.top();
    }
};

int main(){}