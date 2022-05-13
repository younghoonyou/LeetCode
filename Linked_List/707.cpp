struct List{
    List *next, *prev;
    int val;
    List() : next(nullptr), prev(nullptr), val(-1) {}
    List(int data) : next(nullptr), prev(nullptr), val(data) {}
};
class MyLinkedList{
private:
    List *head, *tail;
    int len;
public:
    MyLinkedList(){
        head = new List();
        tail = new List();
        head->next = tail;
        tail->prev = head;
        len = 0;
    }

    int get(int index){
        if (index >= len || index < 0) return -1;
        if (index < len / 2){
            List *temp = head;
            int idx = 0;
            while (idx != index && temp != tail) idx++, temp = temp->next;
            if (temp == tail) return -1;
            return temp->next->val;
        }
        else{
            List *temp = tail;
            int idx = len;
            while (idx != index && temp != head) idx--, temp = temp->prev;
            if (temp == head) return -1;
            return temp->val;
        }
    }

    void addAtHead(int val){
        List *New = new List(val);
        New->next = head->next;
        head->next->prev = New;
        head->next = New;
        New->prev = head;
        len++;
    }

    void addAtTail(int val){
        List *New = new List(val);
        New->prev = tail->prev;
        tail->prev->next = New;
        tail->prev = New;
        New->next = tail;
        len++;
    }

    void addAtIndex(int index, int val){
        if (index < 0 || index > len) return;
        if (index == 0){
            addAtHead(val);
            return;
        }
        else if (index == len){
            addAtTail(val);
            return;
        }
        if (index < len / 2){
            List *temp = head;
            int idx = 0;
            while (idx != index && temp != tail) idx++, temp = temp->next;
            if (temp == tail) return;
            List *New = new List(val);
            New->next = temp->next;
            temp->next->prev = New;
            temp->next = New;
            New->prev = temp;
            len++;
        }
        else{
            List *temp = tail;
            int idx = len;
            while (idx != index && temp != head) idx--, temp = temp->prev;
            if (temp == head) return;
            List *New = new List(val);
            New->prev = temp->prev;
            temp->prev->next = New;
            temp->prev = New;
            New->next = temp;
            len++;
        }
    }

    void deleteAtIndex(int index){
        if (index < 0 || index >= len) return;
        if (index == 0){ // head
            head = head->next;
            len--;
            return;
        }
        else if (index == len - 1){ // tail
            tail = tail->prev;
            len--;
            return;
        }
        if (index < len / 2){
            int idx = -1;
            List *temp = head;
            while (idx != index && temp != tail) idx++, temp = temp->next;
            if (temp == tail) return;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            len--;
        }
        else{
            int idx = len;
            List *temp = tail;
            while (idx != index && temp != head) idx--, temp = temp->prev;
            if (temp == head) return;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            len--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main(){}