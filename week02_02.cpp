// 两数之和

// 用的哈希表,将与目标数的差值存进表内

#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;

        for (int i = 0; i < nums.size(); i++) {
            auto it = mp.find(target-nums[i]);
            if (it != mp.end()) {
                return {it->second, i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};