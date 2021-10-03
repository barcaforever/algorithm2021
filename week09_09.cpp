// 翻转对

// 分治法，时间复杂度o(nlogn)
// 问题分割为子数组1和2里的翻转对，以及1和2之间的翻转对
// 无限二分，直到子数组1和2长度为1，答案为0；问题转化成子问题1和2之间的翻转对个数；
// 子问题解决后再合并，得出最终的翻转对数量；
// 此问题解法就是 分割+求解+合并

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        int nums_sorted[nums.size()];
        memset(nums_sorted, 0, sizeof(nums_sorted));
        return merge_sort(nums, nums_sorted, 0, nums.size() - 1);
    }

    int merge_sort(vector<int>& nums, int nums_sorted[], int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;

        int res = merge_sort(nums, nums_sorted,left, mid) + merge_sort(nums, nums_sorted, mid+1, right) + find_reverse_pairs(nums, left, right);

        int i = left, j = mid + 1, ind = left;


        while (i <= mid && j <= right) {
            if (nums[i] < nums[j]) nums_sorted[ind++] = nums[i++];
            else nums_sorted[ind++] = nums[j++];
        }
        while (i <= mid) nums_sorted[ind++] = nums[i++];
        while (j <= right) nums_sorted[ind++] = nums[j++];

        for (int ind = left; ind <= right; ind++) {
            nums[ind] = nums_sorted[ind];
        }

        return res;
    }

    int find_reverse_pairs(vector<int> &nums, int &left, int & right) {
        int res = 0, mid = left + (right - left) / 2;
        int i = left, j = mid + 1;
        for (; i <= mid; i++) {
            while (j <= right && (long)nums[i] > 2 * (long)nums[j]) {
                res += mid - i + 1; // 从i到mid都符合要求，所以要加上mid-i+1组
                j++;
            }
        }
        return res;
    }
};