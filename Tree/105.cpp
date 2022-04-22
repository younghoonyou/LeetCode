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

class Solution{
public:
    int Index(vector<int> &inorder, int val){ // Find index in inorder
        int j = 0;
        while (inorder[j] != val) j++;
        return j;
    }
    TreeNode *Search(vector<int> &preorder, vector<int> &inorder, int left, int right, int &idx){
        if (left > right || idx >= preorder.size()) return nullptr;//Out of bound
        TreeNode *root = new TreeNode(preorder[idx]);
        int val = preorder[idx++];
        int index = Index(inorder, val);
        root->left = Search(preorder, inorder, left, index - 1, idx);//recursion left side
        root->right = Search(preorder, inorder, index + 1, right, idx);//recursion right side
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
        if (preorder.size() == 0) return nullptr;
        if (preorder.size() == 1) return new TreeNode(preorder[0]);
        int idx = 0;
        return Search(preorder, inorder, 0, inorder.size() - 1, idx);
    }
};

int main(){}