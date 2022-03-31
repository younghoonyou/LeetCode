#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    void Search(vector<string>& answer,string temp,int open,int close){
        if(open == 0 && close == 0){
            answer.push_back(temp);
            return ;
        }
        if(open > 0) Search(answer,temp+"(",open - 1,close);//for condition recursion
        if(close > open) Search(answer,temp+")",open,close - 1);//
    }
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        Search(answer,"",n,n);
        return answer;
    }
};

int main(){}