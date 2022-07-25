#include <iostream>
struct List
{
    int key, val;
    List *next;
    List()
    {
        key = -1;
        val = -1;
        next = nullptr;
    }
    List(int key_, int val_)
    {
        key = key_;
        val = val_;
        next = nullptr;
    }
};
class MyHashMap
{
private:
    List *head;

public:
    MyHashMap()
    {
        head = new List();
    }

    void put(int key, int value)
    {
        List *temp = head;
        while (temp->next && temp->key != key)
        {
            temp = temp->next;
        }
        if (temp->key != key)
        {
            temp->next = new List(key, value);
            temp = temp->next;
        }
        else
        {
            temp->val = value;
        }
    }

    int get(int key)
    {
        List *temp = head;
        while (temp->next && temp->key != key)
        {
            temp = temp->next;
        }
        if (temp->key != key)
        {
            return -1;
        }
        else
        {
            return temp->val;
        }
    }

    void remove(int key)
    {
        List *temp = head;
        while (temp->next && temp->next->key != key)
        {
            temp = temp->next;
        }
        if (temp->next && temp->next->key == key)
        {
            List *Del = temp->next;
            temp->next = temp->next->next;
            delete Del;
        }
    }
};

int main(){}