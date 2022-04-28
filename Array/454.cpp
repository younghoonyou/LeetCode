#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution{//Using hash
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4){
        unordered_map<int, int> map;
        for (int x : nums1){
            for (int y : nums2){
                ++map[x + y];//in advance increase because of 18 lines
            }
        }
        int ans = 0;
        for (int x : nums3){
            for (int y : nums4){
                if (map.find(0 - x - y) != map.end()) ans += map[0 - x - y];//if hash exist add them
            }
        }
        return ans;
    }
};

int main() {}