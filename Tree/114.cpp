#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution{
public:
    TreeNode* Search(TreeNode* root,TreeNode* temp){
        if(!root) return nullptr;
        TreeNode *left = Search(root->left);
        TreeNode *right = Search(root->right);
        temp->right = left;
        temp->right = right;
        return temp;
    }
    void flatten(TreeNode *root){
        TreeNode* temp = Search(root,temp);
        root = temp;
    }
};

int main() {}