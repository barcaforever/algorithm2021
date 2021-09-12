// 最大正方形 

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int row = matrix.size();
        int col = matrix[0].size();

        int maxSize = 0;

        // 用二维数组，记录正方形的长度
        vector<vector<int>> dp(row, vector<int>(col));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                // 只要出现了1，
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        // 在第一行或者第一列 
                        dp[i][j] = 1;
                    }else {
                        // 取左边，上边和左上边的最小值+1
                        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    }
                }
                // 更新正方形的最大长度
                maxSize = max(maxSize, dp[i][j]);
            }
        }

        // 返回最大正方形的面积
        return maxSize * maxSize;

    }
};