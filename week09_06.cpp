// 合并区间

// intervals = [[1,3],[2,6],[8,10],[15,18]]
// 输出：[[1,6],[8,10],[15,18]]

// 原始数组按每个子数组的左边元素大小进行升序排列。
// 新建结果数组，遍历原始数组，在结果数组为空的时候，遍历到的第一个放入结果数组。
// 之后遍历到的每个子数组，如果左边元素比当前结果数组的末尾子数组右边元素还大，那么直接插入到结果数组末尾。如果比结果子数组右边元素小，且
// 结果数组末尾子数组的右边元素比当前遍历的子数组的右边元素大，则替换掉，否则不用操作；
// 以此循环操作，得到最终结果数组。时间复杂度O(1),空间复杂度最大O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;

        for (int i = 0; i < n; i++) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            }else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }

        return merged;

    }
};