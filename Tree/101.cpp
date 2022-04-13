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
    void LeftTree(TreeNode *root,vector<int>&arr){
        if(!root){
            arr.push_back(0);
            return ;
        }
        arr.push_back(root->val);
        LeftTree(root->left,arr);
        LeftTree(root->right,arr);
    }
     void RightTree(TreeNode *root,vector<int>& arr){
        if(!root){
            arr.push_back(0);
            return ;
        }
        arr.push_back(root->val);
        RightTree(root->right,arr);
        RightTree(root->left,arr);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        if(!root->right && !root->left) return true;
        if(!root->right || !root->left) return false;
        vector<int> left;
        vector<int> right;
        LeftTree(root->left,left);
        RightTree(root->right,right);
        for(int i=0;i<left.size();++i){
            if(left[i] != right[i]) return false;
        }
        return true;
    }
};

int main(){}