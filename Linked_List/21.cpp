#include <iostream>
#include <algorithm>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {//single Linked List
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return list1;
        if(!list1 || !list2) return (!list1) ? list2 : list1;
        int tmp;
        if(list1->val >= list2->val) tmp = list2->val , list2 = list2->next;
        else tmp = list1->val , list1 = list1->next;
        ListNode* ans = new ListNode(tmp);
        ListNode* ret = ans;
        while(1){
            if(!list1 && !list2) break;
            if(!list1 && list2) ans->next = new ListNode(list2->val) , list2 = list2->next;
            if(!list2 && list1) ans->next = new ListNode(list1->val) , list1 = list1->next;
            if(list1 && list2){
                int tmp;
            if(list1->val > list2->val) tmp = list2->val , list2 = list2->next;
            else tmp = list1->val , list1 = list1->next;
                ans->next = new ListNode(tmp);
            }
            ans = ans->next;
        }
        return ret;
    }
};

int main(){
    return 0;
}