#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode() : val(0), left(nullptr),right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums,0,nums.size() - 1);
    }
    TreeNode* build(vector<int>& nums,int left,int right){
        if(left>right) return nullptr;
        int mid = (left + right)/2;
        TreeNode *ans = new TreeNode(nums[mid]);
        ans->left = build(nums,left,mid - 1);
        ans->right = build(nums,mid + 1,right);
        return ans;
    }
};

int main(){}