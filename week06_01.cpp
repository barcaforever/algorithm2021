// 最小路径和 

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }

        int row = grid.size();
        int col = grid[0].size();

        // 二维数组，存放从左上角到当前位置的最小路径和
        vector<vector<int>> dp(row, vector<int>(col, 0));

        // 最开始 存放 左上角的值
        dp[0][0] = grid[0][0];

        // 第一列路径和，累加第一列上一行的数字即可
        for (int i = 1; i < row; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        // 第一行路径和，累加第一行上一列的数字即可
        for (int j = 1; j < col; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        // 除了第一行和第一列之外的每个位置，最小路径和都是取左边或者上边较小者，加上当前的数字；
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                dp[i][j] += min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[row-1][col-1];
    }
};