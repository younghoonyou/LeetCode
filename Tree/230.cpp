#include <iostream>
#include <vector>
#include <algorithm>
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
    void search(TreeNode* root,vector<int>& temp){
        if(!root) return ;
        temp.push_back(root->val);
        search(root->left,temp);
        search(root->right,temp);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> answer;
        search(root,answer);
        sort(answer.begin(),answer.end());
        return answer[k-1];
    }
};

int main(){
    Solution s;
    return 0;
}