#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool sector(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                bool map[10] = {
                    false,
                };
                for (int k = i; k < i + 3; ++k)
                {
                    for (int t = j; t < j + 3; ++t)
                    {
                        if (board[k][t] != '.')
                        {
                            if (map[board[k][t] - '0'])
                                return false;
                            map[board[k][t] - '0'] = true;
                        }
                    }
                }
            }
        }
        return true;
    }

    bool vertical(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; ++i)
        {
            bool vmap[10] = {
                false,
            };
            bool hmap[10] = {
                false,
            };
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] != '.')
                {
                    if (hmap[board[i][j] - '0'])
                        return false;
                    hmap[board[i][j] - '0'] = true;
                }
                if (board[j][i] != '.')
                {
                    if (vmap[board[j][i] - '0'])
                        return false;
                    vmap[board[j][i] - '0'] = true;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>> &board)
    {
        // return vertical(board);
        return sector(board) & vertical(board);
    }
};

int main() {}