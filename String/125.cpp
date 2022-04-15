#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string temp = "";
        for (char ch : s)
        {
            if (!isalnum(ch))
                continue;
            temp += tolower(ch);
        }
        int start = 0;
        int end = temp.length() - 1;
        while (start < end)
        {
            if (temp[start] != temp[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};

int main() {}