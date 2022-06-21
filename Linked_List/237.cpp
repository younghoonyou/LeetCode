#include <iostream>
#include <algorithm>
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{//rereference
public:
    void deleteNode(ListNode *node){
        *node = *(node->next);
    }
};

class Solution{//non reference
public:
    void deleteNode(ListNode *node){
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main() {}