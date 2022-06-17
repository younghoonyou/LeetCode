#include <iostream>
#include <algorithm>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode *removeElements(ListNode *head, int val){
        if (!head) return nullptr;
        if (head->val == val) return removeElements(head->next, val);
        ListNode *temp = head;
        while (temp->next){
            if (temp->next->val == val) temp->next = temp->next->next;
            else temp = temp->next;
        }
        return head;
    }
};

int main(){}