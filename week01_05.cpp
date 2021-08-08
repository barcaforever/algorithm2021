// 1 两数之和
// 思路：取一个字典，装入 【给定的和 - 当前值】 ；如果在字典里，则返回对应的下标；

#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> res;
        for (int i = 0; i < nums.size(); i++){

            unordered_map<int, int>::iterator iter = res.find(target - nums[i]);
            if (iter != res.end()){
                return {iter->second, i};
            }
            res[nums[i]] = i;
        }
        return {};
    }
};