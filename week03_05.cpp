// 全排列2 

// 本题包含可重复数字

class Solution {
public:

    // 结果
    vector<vector<int>> res;
    // 子集 - 排列过程中将数字循环地添加进来
    vector<int> path;

    // 标记 - 已经排列过的 true 否则 false 
    vector<int> used;

    void dfs(vector<int>& nums, vector<bool> used) {
        // 递归终止条件：子集 大小 == 初始数组大小
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size() ; i++) {
            // 之前数字已经排列过，且跟当前数字相同，pass
            if (i>0 && nums[i] == nums[i-1] && used[i-1] == true) {
                
                continue;
            }
            // 如果当前数字没排列，则标记并递归 加入到子集当中
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                dfs(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }

        

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // 对重复数字首先去重
        sort(nums.begin(), nums.end());

        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return res;

    }
};