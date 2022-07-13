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
   int minDepth(TreeNode* root) {
    if(root==NULL) return 0;
    
    if(root->left==NULL && root->right==NULL) return 1;
    if(!root->left) return 1+minDepth(root->right);
    if(!root->right) return 1+minDepth(root->left);
            
    return min(minDepth(root->left), minDepth(root->right))+1;
  }
};

int main(){}
