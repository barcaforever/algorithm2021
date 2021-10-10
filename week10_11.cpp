// 通配符匹配

// f[i, j] 表示s[1 .. i] p [1 .. j] 是否匹配


class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        f[0][0] = true;

        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                // 当 p[i] == ’*‘时 
                if (p[j] == '*') {
                    // f[i][j] = f[i][j - 1] ||f[i - 1][j - 1] ||f[i - 2][j - 1]|| ..
                    // f[i - 1][j] = f[i - 1][j - 1] ||f[i - 2][j - 1]|| ..
                    // 所以 f[i][j] = f[i][j - 1] || f[i -1] [j]
                    f[i][j] = f[i][j - 1] || i && f[i - 1][j]; 
                }else {
                    f[i][j] = (s[i] == p[j] || p[j] == '?') && i && f[i - 1][j - 1];
                }
            }
        }

        return f[n][m];

    }
};