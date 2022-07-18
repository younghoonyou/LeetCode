#include <iostream>
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
    vector<int> ans;
    void Search(TreeNode* root){
        if(!root) return;
        ans.push_back(root->val);
        Search(root->left);
        Search(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        Search(root);
        return ans;   
    }
};

int main(){}
