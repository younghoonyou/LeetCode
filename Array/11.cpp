#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> cnt[200];
    int maxArea(vector<int>& height) {
        int size = height.size();
        int max_num = 0;
        for(int i=0;i<size;++i){
          cnt[height[i]].push_back(i);  
          if(max_num < height[i]) max_num = height[i];
        }
        for(int i=0;i<max_num;++i){
            if(cnt[i].empty()) continue;
            
        }
    }
};

int main(){
    vector<int> temp = {
        1,8,6,2,5,4,8,3,7
    };
    Solution s;
    cout<<s.maxArea(temp);
    return 0;
}//Kadane Algorithm O(N)