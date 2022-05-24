#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    bool ans;
    int Search(TreeNode *root){
        if (!root || !ans) return 0;
        int left = Search(root->left); // Preorder
        int right = Search(root->right);
        if (abs(left - right) > 1) ans = false; // diff 2
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode *root){
        if (!root) return true;
        ans = true;
        Search(root);
        return ans;
    }
};

int main() {}