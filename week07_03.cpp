// 有效的数独

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = {0}; // 新建一个二维数组，用来判断 当前行 有没有 重复数字。列数为10，是为了存储第9行；
        int col[9][10] = {0}; // 新建一个二维数组，用来判断 当前列 有没有 重复数字。列数为10，是为了存储第9列；
        int box[9][10] = {0}; // 新建一个二维数组，用来判断 当前3*3的空格内 有没有 重复数字。列数为10，是为了存储第9个；

        for (int i = 0;i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue; // '.'直接跳过
                int cur = board[i][j] - '0'; // 取出当前数字
                if (row[i][cur]) return false; // 已经有了，返回false
                if (col[j][cur]) return false;
                if (box[(i/3)*3 + j/3][cur]) return false;

                row[i][cur] = 1; // 当前行还没有出现这个数字，将这个二维数组在以该数字为下标的地方设为1
                col[j][cur] = 1; // 同理，当前列同样操作
                box[(i/3)*3 + j/3][cur] = 1; // 数独是9*9，一共有9个3*3的空格，当前数字所在的空格数，为(i/3)*3 + j/3
            }
        }
        // cout << row;
        return true;

    }
};