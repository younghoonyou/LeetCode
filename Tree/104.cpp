#include <iostream>
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
    int answer = 0;
    void search(TreeNode* root,int level){
        if(root == nullptr) return ;
        if(answer < level) answer = level;//store level info to answer
        search(root->left,level+1);
        search(root->right,level+1);
    }
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;
        search(root,1);
        return answer;
    }
};

int main(){

    Solution s;
    return 0;
}