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
    ListNode* deleteDuplicates(ListNode* head) {//Memorization
        if(!head || !head->next) return head;
        if(!head->next->next){
            if(head->val == head->next->val) return nullptr;
            return head;
        }
        vector<int> check(201,0);
        int start = head->val;
        while(head->next != nullptr){
            int data = head->val + 100;
            check[data]++;
            head = head->next;
        }
        int last = head->val;
        check[last + 100]++;
        ListNode* answer = new ListNode();
        ListNode* temp = answer;
        for(int i=start + 100;i<=last + 100;++i){
            if(check[i] == 1){
                int data = i - 100;
                answer->next = new ListNode(data);
                answer = answer->next;
            }
        }
        return temp->next;
    }
};

class Solution {//Recursion
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* n = head->next;
        if(n->val!=head->val){
            head->next=deleteDuplicates(n);
            return head;
        }
        else{
            while(n && n->val==head->val)
                n=n->next;
                return deleteDuplicates(n);
        }
    }
};

int main(){

}