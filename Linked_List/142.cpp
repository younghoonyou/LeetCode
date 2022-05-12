#include <iostream>
#include <algorithm>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/*
    Constraints
    use only constant memory
*/
class Solution{//Time Complexity O(N)
public:
    ListNode *detectCycle(ListNode *head){// D + M + R + M = 2(D + M) -> D = R
        if (!head || !head->next) return nullptr;
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast && fast->next){//Does it has cycle?
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return nullptr;//If not
        slow = head;
        while (slow != fast){//D = R theory
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main() {}