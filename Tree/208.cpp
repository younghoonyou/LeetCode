#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class Trie {
private:
    bool finish;
    Trie* alpha[26];
public:
    Trie(){
        memset(alpha,0,sizeof(alpha));
        finish = false;
    }
    
    void insert(string word) {
        Trie* cur = this;//root node
        for(char ch:word){
            if(cur->alpha[ch-'a'] == nullptr) cur->alpha[ch-'a'] = new Trie();
            cur = cur->alpha[ch - 'a'];
        }
        cur->finish = true;
    }
    
    bool search(string word) {
        Trie* cur = this;
        for(char ch:word){
            if(cur->alpha[ch-'a'] == nullptr) return false;
            cur = cur->alpha[ch-'a'];
        }
        if(cur->finish) return true;
        return false;
    }
    
    bool startsWith(string preix) {
        Trie* cur = this;
        for(char ch:preix){
            if(cur->alpha[ch-'a'] == nullptr) return false;
            cur = cur->alpha[ch-'a'];
        }
        return true;
    }
};

int main(){}