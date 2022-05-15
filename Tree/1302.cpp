#include <iostream>
#include <queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{//DFS O(log(N)) -> Tree height
public:
    vector<int> sum;
    void Search(TreeNode *root, int n){
        if (!root) return;
        if (sum.size() < n) sum.emplace_back(0);
        sum[n - 1] += root->val;
        Search(root->left, n + 1);
        Search(root->right, n + 1);
    }
    int deepestLeavesSum(TreeNode *root){
        Search(root, 1);
        return sum[sum.size() - 1];
    }
};

int main() {}