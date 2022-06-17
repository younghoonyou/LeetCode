#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode() : val(0), left(nullptr),right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    int ans = 0;
    int Inorder(TreeNode *root){
        if (!root) return 2;
        int left = Inorder(root->left);
        int right = Inorder(root->right);
        if (left == 0 || right == 0){
            ans++;
            return 1;
        }
        else if (left == 1 || right == 1) return 2;
        else return 0;
    }

    int minCameraCover(TreeNode *root){
        if (!root->left && !root->right) return 1;
        if (Inorder(root) == 0) ans++;
        return ans;
    }
};

int main(){}