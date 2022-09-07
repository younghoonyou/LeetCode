#include <iostream>
#include <string>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode() : val(0), left(nullptr),right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
private:
    string make_str(string s){
        string ret="(" + s + ")";
        return ret;
    }
public:
    string tree2str(TreeNode *root){
        string ret = to_string(root->val);
        if(root->left){
            string left = tree2str(root->left)
            ret += make_str(left);
        }
        if(root->right){
            if(!root->left) ret += make_str("");
            string right = tree2str(root->right);
            ret += make_str(right);
        }
        return ret;
    }
};

int main(){}
