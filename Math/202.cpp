#include <iostream>
#include <algorithm>
using namespace std;
class Solution//Using Hash and Recursion
{
public:
    unordered_map<int, bool> map;
    bool isHappy(int n)
    {
        if (n == 1)
            return true;
        if (map[n])
            return false;
        map[n] = true;
        int val = 0;
        while (n)
        {
            int tmp = n % 10;
            val += tmp * tmp;
            n /= 10;
        }
        return isHappy(val);
    }
};

int main() {}