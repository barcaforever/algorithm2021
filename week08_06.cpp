// N 皇后

class Solution {
private:
    vector<vector<string>> res;
public:
    // n 棋盘大小
    // row 当前递归到哪一行
    void backtracking(int n, int row, vector<string> & chessboard) {
        if (row == n) {
            res.push_back(chessboard);
            return;
        }

        // 遍历列
        for (int col = 0; col < n; col++) {
            if (isValid(row,col,chessboard,n)) {
                chessboard[row][col] = 'Q';
                backtracking(n, row+1, chessboard);
                chessboard[row][col] = '.';
            }
        }
    }

    bool isValid(int row, int col, vector<string>& chessboard, int n) {
        // 同列
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        } 
        // 左上
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // 右上
        for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        std::vector<std::string> chessboard(n, std::string(n, '.'));
        backtracking(n, 0, chessboard);
        return res;

    }
};