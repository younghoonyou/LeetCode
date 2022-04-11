#include <iostream>
#include <algorithm>
#include <unordered_map>
class Node{
    public:
        Node *left,*right;
        int val;
        int key;
        Node() : left(nullptr),right(nullptr),val(-1),key(-1) {}
        Node(int key,int val) : left(nullptr),right(nullptr),val(val),key(key) {}
};
class LRUCache {
public:
    Node *head;
    Node *tail;
    int cnt;
    int idx;
    unordered_map<int,Node*> map;
    void remove(Node *temp){
        temp->left->right = temp->right;
        temp->right->left = temp->left;
        temp->right = nullptr;
        temp->left = nullptr;
        map[temp->key] = nullptr;
    }
    void Make_Node(Node* node,int key,int val){
        Node *New = new Node(key,val);
        New->right = node->right;
        New->left = node;
        node->right->left = New;
        node->right = New;
        map[key] = New;
    }

    LRUCache(int capacity) {
        head = new Node();
        tail = new Node();
        head->right = tail;
        tail->left = head;
        cnt = capacity;
        idx = 0;
    }

    int get(int key) {
        Node *temp = map[key];
        if(!temp) return -1;
        remove(temp);
        int ret = temp->val;
        Make_Node(head,key,ret);
        return ret;
    }
    
    void put(int key, int value) {
        Node *temp = map[key];
        if(temp){
            remove(temp);
            idx--;
        }
        if(idx == cnt){
            Node *tmp = tail->left;
            remove(tmp);
            idx--;
        }
        Make_Node(head,key,value);
        idx++;
    }
};

int main(){}