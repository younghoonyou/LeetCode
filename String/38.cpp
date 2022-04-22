#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Solution{
public:
    string say(int cnt, int n, string temp){
        if (cnt == n) return temp;
        string ret = "";
        char tmp = ' ';
        int cn = 0;
        for (char ch : temp){
            if (ch != tmp){
                if (cn) ret += cn + '0', ret += tmp;
                tmp = ch;
                cn = 1;
            }
            else cn++;
        }
        ret += cn + '0', ret += tmp;
        return say(cnt + 1, n, ret);
    }
    string countAndSay(int n){
        return say(1, n, "1");
    }
};

int main() {}