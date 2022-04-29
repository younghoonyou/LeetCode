#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Solution{ // Using Brute Force O(N^2)
public:
    int kthSmallest(vector<vector<int>> &matrix, int k){
        vector<int> arr;
        for (auto i : matrix)
        for (auto j : i)
            arr.push_back(j);
        sort(arr.begin(), arr.end());
        return arr[k - 1];
    }
};

class Solution{ // Using Heap
public:
    int kthSmallest(vector<vector<int>> &matrix, int k){
        priority_queue<int> q;
        for (auto i : matrix){
            for (auto j : i){
                q.push(j);
                if (q.size() > k) q.pop();
            }
        }
        return q.top();
    }
};

class Solution{ // Using Binary Search O(nlog(K))
public:
    int kthSmallest(vector<vector<int>> &matrix, int k){
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        while (low < high){
            int mid = low + (high - low) / 2; // not use (low + high)/2
            int cnt = 0;
            for (int i = 0; i < n; ++i) cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            if (cnt < k) low = mid + 1;
            else high = mid;
        }
        return high;
    }
};
int main() {}