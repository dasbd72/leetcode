#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isNumberValid(vector<vector<char>>& board, char num) {
        int found = 0;
        for (int r = 0; r < 9; r++) {
            found = 0;
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != num) {
                    continue;
                }
                if (found) {
                    return false;
                }
                found++;
            }
        }
        for (int c = 0; c < 9; c++) {
            found = 0;
            for (int r = 0; r < 9; r++) {
                if (board[r][c] != num) {
                    continue;
                }
                if (found) {
                    return false;
                }
                found++;
            }
        }
        for (int _r = 0; _r < 9; _r += 3) {
            for (int _c = 0; _c < 9; _c += 3) {
                found = 0;
                for (int r = _r; r < _r + 3; r++) {
                    for (int c = _c; c < _c + 3; c++) {
                        if (board[r][c] != num) {
                            continue;
                        }
                        if (found) {
                            return false;
                        }
                        found++;
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 1; i <= 9; i++) {
            if (!isNumberValid(board, i + '0')) {
                return false;
            }
        }
        return true;
    }
};