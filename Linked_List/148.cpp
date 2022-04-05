#include <iostream>
#include <algorithm>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {//Using sort O(N*log(N)) 
public:
    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        vector<int> arr;
        while(head != nullptr){
            arr.push_back(head->val);
            head = head->next;
        }
        sort(arr.begin(),arr.end());
        ListNode* ans = new ListNode();
        ListNode* ret = ans;
        for(int i=0;i<arr.size();++i){
            ans->val = arr[i];
            if(i == arr.size() - 1) continue;
            ans->next = new ListNode();
            ans = ans->next;
        }
        return ret;
    }
};