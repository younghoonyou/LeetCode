#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int firstBadVersion(int n) {
        long long start = 1,end = n;
        while(start<=end){
            long long mid = (start + end)/2;
            if(isBadVersion(mid)) end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};//Binary Search O(log(N))

int main(){
    
}