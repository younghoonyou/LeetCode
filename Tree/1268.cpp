#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Trie{
    private:
        Trie *alpha[26];
        bool check;
    public:
        Trie(){
            for(int i=0;i<26;++i) alpha[i] = nullptr;
            check = false;
        }
        void add(string s){
            if(s.length() == 1){
                check = true;
                return;
            }
            if(!alpha[s[0] - 'a')) alpha[s[0] - 'a'] = new Trie;
            add(s.substr(1, s.length() - 1));
        }
        void search(){

        }
};

int main(){}