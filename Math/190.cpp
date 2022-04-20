#include <iostream>
#include <algorithm>
using namespace std;
class Solution//Using Shift operator and Bit
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans;
        for (int i = 0; i < 32; ++i)//because of 32 bit
        {
            ans <<= 1;
            if (n & 1)
                ans++;//Make bit
            n >>= 1;//inspect from right to left
        }
        return ans;
    }
};

int main() {}