#include <iostream>
#include <algorithm>
using namespace std;
class Solution{
public:
    int missingNumber(vector<int> &nums){//Using sum Cal O(N) , O(1) -> conditino 0 ~ N
        int sum = 0;
        int n = nums.size();
        for (int x : nums)
            sum += x;
        return (n * (n + 1)) / 2 - sum;
    }
};

class Solution{
public:
    int missingNumber(vector<int> &nums){//O(N) O(1) -> condition 0 ~ N
        int result = nums.size();
        int i = 0;
        for (int num : nums){
            result ^= num;
            result ^= i;
            i++;
        }
    }// We know a^a = 0
};//if [3,0,1] -> 3^3^0^0^1^1^2 -> 2

int main() {}