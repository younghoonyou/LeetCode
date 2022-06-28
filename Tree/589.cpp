#include <iostream>
#include <vector>
using namespace std;
class Node{
public:
    int val;
    vector<Node *> children;
    Node() {}

    Node(int _val){
        val = _val;
    }

    Node(int _val, vector<Node *> _children){
        val = _val;
        children = _children;
    }
};
class Solution{
private:
    vector<int> ans;
public:
    vector<int> preorder(Node *root){//Using Recursion
        if (!root) return {};
        int size = root->children.size();
        ans.push_back(root->val);
        for (int i = 0; i < size; ++i) preorder(root->children[i]);
        return ans;
    }
};
int main(){}