#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    int maxOperations(vector<int> &nums, int k){
        unordered_map<int, int> hash;
        int ans = 0;
        for (int x : nums) hash[x]++;

        for (int x : nums){
            if (hash[x] && hash[k - x]){
                if (x == k - x){
                    if (hash[x] >= 2){
                        hash[x] -= 2;
                        ans++;
                    }
                }
                else{
                    hash[x]--;
                    hash[k - x]--;
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {}