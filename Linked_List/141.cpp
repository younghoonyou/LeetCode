#include <iostream>
#include <algorithm>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{//Using space complexity O(1)
public:
    bool hasCycle(ListNode *head){
        if (!head || !head->next) return false;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;
    }
};

int main(){
    return 0;
}