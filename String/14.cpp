#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {//sort and compare just start , end
        int size = strs.size();
        if(size == 1) return strs[0];
        sort(strs.begin(),strs.end());
        int len = strs[0].length();
        string first = strs[0];
        string end = strs[size - 1];
        string temp = "";
        for(int i=0;i<len;++i){
            if(first[i] != end[i]) return temp;
            temp+=first[i];
        }
        return temp;
    }
};
int main(){

}