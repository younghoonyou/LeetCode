#include <iostream>
#include <algorithm>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {//O(1) Linked_List
        if(!head) return false;
        if(!head->next) return false;
        while(head->next !=nullptr){
            if(head->val == 100001) return true;
            head->val = 100001;
            head = head->next;
        }
        return false;
    }
};//Change Data = check


int main(){
    return 0;
}