#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0);
    }
    bool check(vector<vector<char>>& board, int idx) {
        int r = idx / 9, c = idx % 9;
        int br = r / 3 * 3, bc = c / 3 * 3;
        // check row
        for (int i = 0; i < 9; i++) {
            if (i != c && board[r][i] == board[r][c]) {
                return false;
            }
        }
        // check col
        for (int i = 0; i < 9; i++) {
            if (i != r && board[i][c] == board[r][c]) {
                return false;
            }
        }
        // check block
        for (int i = 0; i < 9; i++) {
            if (br + i / 3 != r && bc + i % 3 != c && board[br + i / 3][bc + i % 3] == board[r][c]) {
                return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<char>>& board, int idx) {
        if (idx == 81) {
            return true;
        }
        int r = idx / 9, c = idx % 9;
        if (board[r][c] == '.') {
            for (int i = 1; i <= 9; i++) {
                board[r][c] = '0' + i;
                if (check(board, idx) && dfs(board, idx + 1)) {
                    return true;
                }
                board[r][c] = '.';
            }
        } else {
            if (dfs(board, idx + 1)) {
                return true;
            }
        }
        return false;
    }
};