#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode() : val(0), left(nullptr),right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {//O((logN)^2) -> worst O(N^2)
public:
    TreeNode* node;
    bool flag = false;
    bool cmp(TreeNode* node,TreeNode* root){
        if(!node && !root) return true;
        if(!node || !root) return false;
        if(node->val != root->val) return false;
        return cmp(node->left,root->left) & cmp(node->right,root->right);
    }
    void search(TreeNode* root,int val){
        if(!root) return ;
        if(root->val == val){
            flag |=cmp(root,node);//because duplication of below node value
        }
        search(root->left,val);
        search(root->right,val);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        node = subRoot;
        search(root,subRoot->val);
        return flag;
    }
};

int main(){
    
}