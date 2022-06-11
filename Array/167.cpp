#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{//Using Hash Map
public:
    vector<int> twoSum(vector<int> &numbers, int target){
        unordered_map<int, int> map;
        vector<int> ans;
        for (int i = 0; i < numbers.size(); ++i){
            map[numbers[i]] = i;
        }
        for (int i = 0; i < numbers.size(); ++i){
            if (map.find(target - numbers[i]) != map.end()){
                int first = map[target - numbers[i]];
                int second = i;
                if (first > second) swap(first, second);
                ans.push_back(first + 1);
                ans.push_back(second + 1);
                break;
            }
        }
        return ans;
    }
};

class Solution{//Using Two Pointer -> It is sorted
public:
    vector<int> twoSum(vector<int> &numbers, int target){
        int start = 0;
        int end = numbers.size() - 1;
        while (start < end){
            int sum = numbers[start] + numbers[end];
            if (sum > target) end--;
            else if (sum < target) start++;
            else return {start + 1, end + 1};
        }
        return {-1, -1};
    }
};

int main() {}