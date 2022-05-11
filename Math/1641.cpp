#include <iostream>
#include <algorithm>
using namespace std;
/*
    a = a + e + i + o + u;
    e = e + i + o + u;
    i = i + o + u;
    o = o + u;
    u = u;
*/
class Solution{
public:
    int countVowelStrings(int n){
        int a, e, i, o, u;
        a = e = i = o = u = 1;
        while (--n){
            o += u;
            i += o;
            e += i;
            a += e;
        }
        return a + e + i + o + u;
    }
};

int main() {}