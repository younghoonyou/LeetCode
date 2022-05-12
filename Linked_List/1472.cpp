#include <iostream>
#include <algorithm>
struct List{
        string data;
        List *next,*prev;
        List(string url):next(nullptr),prev(nullptr),data(url){}
};
class BrowserHistory {
private:
    List *cur;
public:
    BrowserHistory(string homepage) {
        cur = new List(homepage);
    }
    
    void visit(string url) {//O(1)
        cur->next = new List(url);
        cur->next->prev = cur;
        cur = cur->next;
    }
    
    string back(int steps) {//O(1)
        while(cur->prev && steps--) cur = cur->prev;
        return cur->data;
    }
    
    string forward(int steps) {//O(1)
        while(cur->next&& steps--) cur = cur->next;
        return cur->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

int main(){}