#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class MinStack
{
private:
    vector<int> arr;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        arr.push_back(val);
    }

    void pop()
    {
        arr.pop_back();
    }

    int top()
    {
        return arr.back();
    }

    int getMin()
    {
        return *min_element(arr.begin(), arr.end());
    }
};

int main() {}