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

class Solution{//O(3/2*N + 1)
public:
    bool isPalindrome(ListNode *head){
        vector<int> arr;
        while(head)
            arr.push_back(head->val), head = head->next;
        int start = 0,end = arr.size() - 1;
        while(start<end){
            if(arr[start]!=arr[end])
                return false;
            start++, end--;
        }
        return true;
    }
};

class Solution{
public:
    bool isPalindrome(ListNode *head){
        ListNode *slow , *fast;
        slow = fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = nullptr;
        
    }
};

//[1,0,1]
int main() {}