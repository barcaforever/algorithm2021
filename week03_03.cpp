// 组合 

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtrace(int n, int k, int startIndex) {

        // 回溯
        
        // 终止条件：子集的大小等于K 
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        //  回溯，从startIndex开始，找到子集后再找下一个数的startIndex
        //  做了剪枝,上一个数跟当前数的重合子集部分不用再放入结果集当中了
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtrace(n, k, i + 1);
            path.pop_back();
        }

    }

    // 组合 主函数
    vector<vector<int>> combine(int n, int k) {

        backtrace(n, k, 1);
        return res;


    }
};