#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix){
        int N = matrix.size();
        int M = matrix[0].size();
        vector<int> ans;
        const int dx[4] = {0, 1, 0, -1}; // right,down,left,up
        const int dy[4] = {1, 0, -1, 0};
        int change = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        ans.push_back({matrix[0][0]});
        matrix[0][0] = 101;
        while (!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int nx = x + dx[change];
            int ny = y + dy[change];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || matrix[nx][ny] == 101){
                change++;
                change %= 4;
                nx = x + dx[change];
                ny = y + dy[change];
            }
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || matrix[nx][ny] == 101) break;
            ans.push_back(matrix[nx][ny]);
            matrix[nx][ny] = 101;
            q.push({nx, ny});
        }
        return ans;
    }
};

int main(){}