#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution{ // O(2^(h+1)-2+h)
public:
    void Search(Node *root, vector<vector<Node *>> &height, int n){
        if (!root) return;
        if (height.size() <= n) height.push_back({});
        height[n].push_back(root);
        Search(root->left, height, n + 1);
        Search(root->right, height, n + 1);
    }
    Node *connect(Node *root)
    {
        vector<vector<Node *>> height;
        Search(root, height, 0);
        for (int i = 0; i < height.size(); ++i) {
            for (int j = 0; j < height[i].size() - 1; ++j) {
                height[i][j]->next = height[i][j + 1];
            }
        }
        return root;
    }
};

int main() {}