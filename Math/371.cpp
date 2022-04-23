#include <iostream>
#include <algorithm>
using namespace std;
class Solution{
public:
    int getSum(int a, int b){//Using Bit
        if (!b) return a;//if b == 0
        return getSum(a ^ b, (int)((long long unsigned int)(a & b) << 1));//Bit manipulate
    }
};

int main() {}