#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution{//Using stack
public:
    int longestValidParentheses(string s){
        stack<int> st;
        int ans = 0;
        st.push(-1); // because first word can be ')'
        for (int i = 0;i<s.length();++i){// O(N)
            if(s[i] == '(') st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else{
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }
};

class Solution{
    public:
        int longestValidParentheses(string s){//Using Dynamic Programming
            int n = s.length();
            int ans = 0;
            vector<int> dp(n, 0);
            int right = (s[0] == '(') ? 1:0;
            for(int i=1;i<n;++i){// O(N)
                if(s[i] == '('){
                    dp[i] = 0;
                    right++;
                }
                else{
                    if(right == 0) dp[i] = 0;// '('cnt > ')'cnt
                    else{
                        dp[i] = dp[i - 1] + 2;
                        if(i > dp[i]){
                            dp[i] += dp[i - dp[i]];
                        }
                        right--;
                    }
                }
                ans = max(ans, dp[i]);
            }
            return ans;
        }
};

int main() {}