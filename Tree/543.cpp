#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution//Using recursion O(N)
{
private:
    int answer(TreeNode *root, int &val)
    {
        if (!root)
            return 0;
        int left = answer(root->left, val);
        int right = answer(root->right, val);
        val = max(val, left + right);
        return max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        int ret = 0;
        answer(root, ret);
        return ret;
    }
};

int main()
{
}