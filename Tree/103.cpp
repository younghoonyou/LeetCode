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

class Solution // Using Tree O(2^h - 1 + N);
{
public:
    void Search(TreeNode *root, int n, vector<vector<int>> &ans)
    {
        if (!root)
            return;
        if (ans.size() <= n)
            ans.push_back({});
        ans[n].push_back(root->val);
        Search(root->left, n + 1, ans);
        Search(root->right, n + 1, ans);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> ans;
        Search(root, 0, ans);
        for (int i = 1; i < ans.size(); i += 2)
            reverse(ans[i].begin(), ans[i].end());//O(N)
        return ans;
    }
};
int main() {}