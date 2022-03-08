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
    int max_level = 0;
    vector<int> temp[2000];
    void search(TreeNode *root,int level){
        if(!root) return ;
        temp[level].push_back(root->val);
        if(max_level < level) max_level = level;
        search(root->left,level+1);
        search(root->right,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > answer;
        if(!root) return answer;
        if(root->left == nullptr && root->right == nullptr){
            temp[0].push_back(root->val);
            answer.push_back(temp[0]);
            return answer;
        }
        search(root,0);
        for(int i=0;i<=max_level;++i) answer.push_back(temp[i]);
        return answer;
    }
};

int main(){

}