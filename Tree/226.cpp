#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// class Solution {
// public:
//     void PostOrder(TreeNode *temp){
//         if(temp == nullptr) return ;
//         TreeNode *node = temp->right;//just change order
//         temp->right = temp->left;
//         temp->left = node;
//         PostOrder(temp->right);
//         PostOrder(temp->left);
//     }

//     TreeNode* invertTree(TreeNode* root) {
//         PostOrder(root);
//         return root;
//     }
// };

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode *tmp = root->left;
        root->left=root->right;
        root->right=tmp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

int main(){
    vector<int> temp = {
        4,2,7,1,3,6,9
    };
    TreeNode head;
    head.right = nullptr;
    TreeNode* box = (TreeNode*)malloc(sizeof(TreeNode)*7);
    for(int i=0;i<temp.size();++i){
        box[i].right = head.right;
        box[i].val = temp[i];
        head.right = &box[i];
    }
    TreeNode *start = &head;
    Solution s;
    TreeNode* answer = s.invertTree(start);
    while(answer){
        cout<<answer->val<<" ";
        answer = answer->right;
    }

    return 0;
}