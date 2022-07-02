#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
private:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1] > b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int totalUnits = 0;
        for (auto& box : boxTypes) {
            int numBoxes = min(truckSize, box[0]);
            totalUnits += numBoxes * box[1];
            truckSize -= numBoxes;
        }
        return totalUnits;
    }
};

int main() {}