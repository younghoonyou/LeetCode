#include <iostream>
#include <vector>
#include <algorithm>
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
    void search(TreeNode* root,int& k,int& ans){
        if(!root) return ;
        search(root->left,k,ans);
        if(k == 0) ans = root->val;
        k--;
        search(root->right,k,ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        k--;
        search(root,k,ans);
        return ans;
    }
};

int main(){}