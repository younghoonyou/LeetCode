#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode() : val(0), left(nullptr),right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {//전위순회 접근
    TreeNode *prev = nullptr;//
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;//루트가 null이면
        if(!isValidBST(root->left)) return false;//
        if(prev && prev->val >= root->val) return false;//
        prev = root;//루트로 초기화
        if(!isValidBST(root->right)) return false;
        return true;
    }
};

int main(){
    Solution s;
    bool t = s.isValidBST()
    if(t){
        cout<<"Answer!!";
    }
    else cout<<"Error!!";
    return 0;
}