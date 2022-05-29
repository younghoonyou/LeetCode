#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution{//Bit masking
public:
    int maxProduct(vector<string> &words){
        int ans = 0;
        vector<int> mask(words.size());
        for (int i = 0;i<words.size();++i){
            for(char ch:words[i]) mask[i] |= 1 << (ch - 'a');
            for (int j = 0;j<i;++j){
                if(!(mask[i] & mask[j])){
                    int temp = words[i].length() * words[j].length();
                    ans = max(ans,temp);
                }
            }
        }
        return ans;
    }
};

class Solution{//O(N * length(N))
public:
    int maxProduct(vector<string> &words){
        int ans = 0;
        for (int i = 0; i < words.size() - 1; ++i){
            bool alpha[26] = {false,};
            for (char ch : words[i]) alpha[ch - 'a'] = true;
            for (int j = i + 1; j < words.size(); ++j){
                bool flag = false;
                for (char ch : words[j]){
                    if (alpha[ch - 'a']){
                        flag = true;
                        break;
                    }
                }
                if (!flag){
                    int temp = words[i].length() * words[j].length();
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};
int main() {}