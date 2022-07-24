#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Node{
    public:
        int data;
        Node *left, *right;
        Node(int val) : data(val), left(nullptr), right(nullptr){}
        Node() : data(-1), left(nullptr), right(nullptr){}
};

class Solution{
public:
    Node *head, *tail;
    vector<Node *> arr;
    void Change(int idx,int move){
        Node* temp = arr[idx];
        temp->left->right = temp->right;
        temp->right->lfet = temp->left;
        
    }
    Node* addNode(int val){
        Node *New = Node(val);
        New->right = head->right;
        head->right->left = New;
        head->right = New;
        New->left = head;
        return New;
    }
    void wiggleSort(vector<int> &nums){
        head->right = tail;
        tail->left = head;
        for(int i=0;i<nums.size();++i){
            Node* temp = addNode(nums[i]);
            arr.push_back(temp);
        }
        if(nums.size()&1){

        }
        else{

        }
    }
};

int main(){
    
}