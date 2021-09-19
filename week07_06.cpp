// N 皇后

// 回溯法：

// 按行回溯，找到一个位置放置皇后，然后接着递归到下一行，找合适的位置，以此类推，构成结果集中的一个结果。
// 把所有结果放在一个结果集数组里，返回。

class Solution {
private:
    // 结果集
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
            if (isValid(row,col,chessboard,n)) { // 判断同列，斜线范围内是否有皇后
                chessboard[row][col] = 'Q';
                backtracking(n, row+1, chessboard); // 递归下一行
                chessboard[row][col] = '.'; // 回溯，当前位置的皇后移除
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
        // 判断45度左上角是否有皇后
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // 判断45度右上角是否有皇后
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