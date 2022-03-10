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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int level = inorder.size();
        int cnt = 0;
        while(level){
            level/=2;
            cnt++;
        }
        TreeNode root(preorder[0]);
        TreeNode* answer;
        return answer;
    }
};

int main(){
    Solution s;
    return 0;
}