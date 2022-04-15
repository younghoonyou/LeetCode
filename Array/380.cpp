#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class RandomizedSet {
private:
    vector<int> arr;
    unordered_map<int,int> m;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(m.find(val)!=m.end()) return false;
        m[val] = arr.size();
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val) == m.end()) return false;
        int last=arr.back();
        arr[m[val]]=arr.back();
        arr.pop_back();
        m[last]=m[val];
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

int main(){}