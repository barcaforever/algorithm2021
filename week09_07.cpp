// 最长 上升子序列

// nums = [10,9,2,5,3,7,101,18]
// 输出：4
// 最长递增子序列是 [2,3,7,101]

// 初始 dp = [1,1,1,1,1,1,1,1]
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        // 以每个元素为结尾的子序列的最大长度，初始值均为1；
        vector<int> dp(nums.size(), 1);
        
        int ans = 1;
        for (int i = 1; i < nums.size(); i++){
            // 从第二个数开始，记录以每个数为结尾的子序列长度
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    // 如果j位置比i位置小，则以i位置为结尾的最长子序列的长度可能会更新，取决于j位置结尾的子序列的长度+1跟当前位置的子序列最大长度的比较；
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                // 不断更新最长的子序列值；
                if (dp[i] > ans) ans = dp[i];
            }
        }
        return ans;
    }
};