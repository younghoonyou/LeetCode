#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution{
public:
    bool find132pattern(vector<int> &nums){
        //condition (1) S1<S2 , (2) S1<S3 , (3) S3<S2
        int n = nums.size();
        vector<int> mins(n, 0);//S1
        stack<int> s;//S2
        mins[0] = nums[0];
        for (int i = 1; i < n; ++i) mins[i] = min(nums[i], mins[i - 1]);
        for (int j = n - 1; j > 0; j--){
            if (nums[j] > mins[j]){//condition 2
                while (s.size() > 0 && s.top() <= mins[j]) s.pop();//To meet condition 3
                if (s.size() > 0 && s.top() < nums[j]) return true;//condition 1
                s.push(nums[j]);
            }
        }
        return false;
    }
};

int main() {}