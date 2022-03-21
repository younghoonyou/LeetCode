#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    vector<Node*> pointer[200];
    void find(int n,Node* root){
        if(!root) return ;
        pointer[n].push_back(root);
        find(n+1,root->left);
        find(n+1,root->right);
    }
    void answer(int n,Node* root,vector<int>& index){
        if(!root) return ;        
        if(pointer[n].size() > 1 && pointer[n].size() != index[n]){
            root->next = pointer[n][index[n]];
            index[n]++;
        }
        answer(n+1,root->left,index);
        answer(n+1,root->right,index);
    }
    Node* connect(Node* root) {
        vector<int> index(200,1);
        if(!root) return root;
        find(1,root);
        answer(1,root,index);
        return root;
    }
};
int main(){
    
}