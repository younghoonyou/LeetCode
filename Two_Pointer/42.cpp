#include <iostream>
#include <algorithm>
class Solution{
public:
    int trap(vector<int> &height){
        int start,end;
        int sum = 0;
        start = end = 0;
        while(height[start]) start++,end++;
        while (start<=end && end < height.size()){
            int cnt = 0;
            end++;
            while (height[start] < height[end]){
                cnt += height[start] - height[end];
                end++;
            }
            sum += cnt;
            start = end;
        }
        return sum;
    }
};

int main() {}