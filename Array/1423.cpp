#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size();
        int ans = 0;
        for(int i=0;i<k;++i) ans += cardPoints[i];
        int tmp = ans;
        for(int i=k-1;i>=0;i--){
            tmp -= cardPoints[i];
            tmp += cardPoints[size - k + i];
            ans = max(ans,tmp);
        }
        return ans;
    }
};
int main(){}
