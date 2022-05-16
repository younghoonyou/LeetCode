#include <iostream>
#include <algorithm>
#include <vector>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{//
public:
    ListNode *rotateRight(ListNode *head, int k){
        if (!head || !head->next || k == 0) return head;
        ListNode *tmp = head;
        vector<ListNode *> list;
        while (tmp) list.emplace_back(tmp), tmp = tmp->next;
        k %= list.size();
        if (k == 0) return head;
        ListNode *temp = list[list.size() - k - 1];
        temp->next = nullptr;
        list[list.size() - 1]->next = head;
        return list[list.size() - k];
    }
};

class Solution{//
public:
    ListNode *rotateRight(ListNode *head, int k){
        if (!head || !head->next || k == 0) return head;
        int len = 1;
        ListNode *tmp = head;
        while(tmp->next) len++,tmp = tmp->next;
        k %= len;
        if(k == 0 || len == 1) return head;
        int start = 1;
        ListNode *temp = head;
        while (start != len - k) start++,temp = temp->next;
        ListNode *ans = temp->next;
        temp->next = nullptr;
        tmp->next = head;
        return ans;
    }
};

class Solution{
public:
    ListNode *rotateRight(ListNode *head, int k){
        if (!head || !head->next || k == 0) return head;
        int len = 1;
        ListNode *tmp = head;
        while (tmp->next) len++, tmp = tmp->next;
        k %= len;
        if (k == 0 || len == 1) return head;
        int start = 1;
        ListNode *temp = head;
        while (start != len - k) start++, temp = temp->next;
        ListNode *ans = temp->next;
        temp->next = nullptr;
        tmp->next = head;
        return ans;
    }
};
int main() {}