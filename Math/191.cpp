#include <iostream>
#include <algorithm>
using namespace std;
class Solution{
public:
    int hammingWeight(uint32_t n){
        int ret = 0;
        while (n){
            if (n & 1) ret++;
            n = n >> 1;
        }
        return ret;
    }
};

class Solution//Using Bit Masking
{
public:
    int hammingWeight(uint32_t n)
    {
        int ret = 0;
        for (int i = 0; i < 32; ++i)
        {
            if (n & (1 << i))
                ret++;
        }
        return ret;
    }
};

int main() {}