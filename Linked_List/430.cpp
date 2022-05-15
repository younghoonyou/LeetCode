#include <iostream>
using namespace std;
class Node{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

class Solution{//Recursion O(N) actually less than O(N)
public:
    Node *flatten(Node *head){
        if (!head) return head;
        Node *temp = head;
        while (!temp->child && temp->next) temp = temp->next;
        if (!temp->next && !temp->child) return head;
        Node *tmp = flatten(temp->child);
        Node *back = tmp;
        while(back->next) back = back->next;
        back->next = temp->next;
        if (temp->next) temp->next->prev = back;
        tmp->prev = temp;
        temp->next = tmp;
        temp->child = nullptr;
        return head;
    }
};

int main(){}