#include <iostream>
#include <algorithm>
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head)
            return nullptr;
        if (!head->next && n == 1)
            return nullptr;
        unordered_map<int, ListNode *> map;
        ListNode *temp = head;
        int cnt = 1;
        while (temp)
        {
            if (n == 1 && !temp->next->next)
            {
                break;
            }
            map[cnt] = temp;
            cnt++;
            temp = temp->next;
        }
        if (n == 1)
        {
            temp->next = temp->next->next;
            return head;
        }
        ListNode *point = map[cnt - n];
        *point = *point->next;
        return head;
    }
};

int main() {}