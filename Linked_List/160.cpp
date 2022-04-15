#include <iostream>
#include <algorithm>
#include <unordered_map>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{//Don't forget hash can contain Node
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        unordered_map<ListNode*,bool> map;
        while(headA) map[headA] = true,headA = headA->next;
        while(headB){
            if(map[headB]) return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};

int main(){}