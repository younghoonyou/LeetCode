#include <iostream>
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
    vector<int> ans;
    void Search(TreeNode *root, int lvl){
        if (!root) return;
        if (ans.size() == lvl) ans.push_back(root->val);
        Search(root->right, lvl + 1);
        Search(root->left, lvl + 1);
    }
    vector<int> rightSideView(TreeNode *root){
        Search(root, 0);
        return ans;
    }
};

int main(){}