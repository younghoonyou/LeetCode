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
    ListNode* node = new ListNode();
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* temp = head->next;
        if(!temp){
            head->next = node->next;
            return head;
        }
        if(!node){
            node = head->next;
            node->next = head;
            head->next = nullptr;
            return reverseList(temp);
        }
        else{
            head->next = node->next;
            node->next = head;
            return reverseList(temp);
        }
        return head;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      if(!head || !(head->next))  return head;
        ListNode* res = reverseList(head->next);//Tail Node;
        head->next->next = head;
        head->next = NULL;
        return res;//Start from reverse
    }
};


int main(){
    return 0;
}