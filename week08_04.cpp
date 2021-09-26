// 岛屿数量

// DFS 将查询每个点周围四个点是否是岛屿，转化成查询这个点为根节点的四叉树的结点是否也是岛屿的思路，套用二叉树的DFS查询规则即可；

class Solution {
private:

    void dfs(vector<vector<char>>& grid, int r, int c) {

        // 越界条件
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) {
            return;
        }

        // 如果不是岛屿，返回
        if (grid[r][c] != '1') {
            return;
        }

        // 是岛屿，标记一下，防止重复搜索
        grid[r][c] = '2';

        dfs(grid, r-1, c);
        dfs(grid, r+1, c);
        dfs(grid, r, c-1);
        dfs(grid, r, c+1);
    }

public:

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        if (row == 0 || col == 0) {
            return res;
        }

        // 开始从0，0搜索
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // 遇到岛屿，数量res+1， 同时开始dfs
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    res += 1;
                }
            }
        }

        return res;
    }
};

