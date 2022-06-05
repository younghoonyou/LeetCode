#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution{
private:
    vector<vector<string>> ans;
    vector<string> ret;
    int N;
    int Q;
    const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    bool condition(int x, int y){
        if (x < 0 || y < 0 || x >= N || y >= N) return false;
        else return true;
    }

public:
    bool check(int x, int y){
        for (int i = 0; i < 8; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            while (condition(nx, ny) && ret[nx][ny] != 'Q') nx += dx[i], ny += dy[i];
            if (!condition(nx, ny)) continue;
            else if (ret[nx][ny] == 'Q') return false;
        }
        return true;
    }
    void Search(int level, int q_cnt){
        if (level == N){
            ans.push_back(ret);
            return;
        }
        for (int i = 0; i < N; ++i){
            if (check(level, i)){
                ret[level][i] = 'Q';
                Search(level + 1, q_cnt + 1);
                ret[level][i] = '.';
            }
        }
    }
    int totalNQueens(int n){
        N = n;
        Q = -1;
        string str = "";
        for (int i = 0; i < n; ++i){
            str += '.';
        }
        for (int i = 0; i < n; ++i){
            ret.push_back(str);
        }
        Search(0, 0);
        return ans;
    }
};

int main() {}