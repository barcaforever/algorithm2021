// 547 省份数量 

// 并查集 

// init 初始化 数组里存储每个数的根节点，初始化时存储自己本身
// find,merge 查询和合并操作，将具有相同根节点的节点放到一个集合里去

// 建立好并查集之后，对数组内的集合进行查询。如果是1 且 已经merge，则 数量+1；

class Solution {
private:
    vector<int> fa;
    void init(int N) {
        fa.resize(N);
        for (int i = 0; i < N; i++) {
            fa[i] = i;
        }
    }

    int find(int x) {
        int r = x;
        while (fa[r] != r) {
            r = fa[r];
        }
        while (fa[x] != x) {
            int t = fa[x];
            fa[x] = r;
            x = t;
        }
        return x;
    }

    bool merge(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru == rv) {
            return false;
        }
        fa[ru] = rv;
        return true;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        init(n);
        int res = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1 && merge(i, j)){
                    res -= 1;
                }
            }
        }
        return res;
    }
};