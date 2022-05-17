#include <iostream>
#include <queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{//O(log(N))
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target){
        if (!original) return nullptr;
        if (original == target) return cloned;
        TreeNode *left = getTargetCopy(original->left, cloned->left, target);
        TreeNode *right = getTargetCopy(original->right, cloned->right, target);
        if (left) return left;
        if (right) return right;
        return nullptr;
    }
};

int main() {}