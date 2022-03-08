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
    int store;
    int maxPathSum(TreeNode* root) {
        if(!root){
            if(store < 0) return -987654321;
            else return 0;
        }
        store = root->val;
        int max_left = maxPathSum(root->left);
        int max_right = maxPathSum(root->right);
        if(!(max_left | max_right)) return root->val;
        int temp = max_left + max_right + root->val;
        int max_num = max(max_left,max_right);
        return max(max(temp,root->val),max(max_num + root->val,max_num));
    }
};

int main(){

}