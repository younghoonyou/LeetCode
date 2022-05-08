#include <iostream>
#include <vector>
using namespace std;

class NestedInteger {
    public:
      bool isInteger() const;
      // Return true if this NestedInteger holds a single integer, rather than a nested list.
      int getInteger() const;
      // Return the single integer that this NestedInteger holds, if it holds a single integer
      const vector<NestedInteger> &getList() const;
      // Return the nested list that this NestedInteger holds, if it holds a nested list
 };

 class NestedIterator{
 private:
     vector<int> flat;//using vector
     int idx;
     void Make_Flatten(NestedInteger val){
         if (val.isInteger()) flat.push_back(val.getInteger());//if integer
         else{//if list
             for (auto x : val.getList()) Make_Flatten(x); // recursion until integer
         }
     }

 public:
     NestedIterator(vector<NestedInteger> &nestedList){
         idx = 0;
         for (auto x : nestedList) Make_Flatten(x);
     }

     int next(){
         return flat[idx++];
     }

     bool hasNext(){
         return idx < flat.size();//
     }
 };

int main(){}
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */