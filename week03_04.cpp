// 全排列

class Solution {
public:

    // 结果集
    vector<vector<int>> res;
    // 子集
    vector<int> path;
    
    void dfs(vector<int>& nums, vector<bool>& used) {

        // 终止条件：子集大小==初始数组大小，表明已经全部排列过了
        if (path.size() == nums.size())
        {
            // 将子集加入结果集
            res.push_back(path); // 已经形成了一组[1,2,3]
            return;
        }

        // 需要做去重，用bool值做标记
        for (int i = 0; i < nums.size(); i++) {
            // 标记当前数为排列过的，以后不用重复排
            if (used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            // 递归 继续找满足条件的排列
            dfs(nums, used);
            path.pop_back();
            used[i] = false;
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return res;
    }
};