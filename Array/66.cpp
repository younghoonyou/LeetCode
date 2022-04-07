#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size() - 1;
        while(1){
            if(index == 0 && digits[index] == 9){
                digits[index] = 1;
                digits.push_back(0);
                break;
            }
            digits[index]++;
            if(digits[index]!=10) break;
            digits[index] = 0;
            index--;
        }
        return digits;
    }
};

int main(){
    
}