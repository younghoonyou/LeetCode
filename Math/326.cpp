#include <iostream>
#include <algorithm>
using namespace std;
class Solution{
public:
    bool isPowerOfThree(int n){
        if (n <= 0) return false;
        int const Max3PowerInt = 1162261467;
        return (Max3PowerInt % n == 0) ? true : false;
    }
};

int main() {}