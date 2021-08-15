// 49 字母异位词分组
// 哈希表，先对每个字符串按照字母顺序进行排序，这样异位词就能按照同一个Key存到表内；
// 全部存完后，再用一个二维数组取出；

#include <vector>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string, vector<string>>mp;

        for (auto str : strs) {
            auto tmp = str;
            // 每个字符串排序，异位词的字符串排序后作为Key是同一个；
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(str);
        }
        for (auto elem : mp) {
            res.push_back(elem.second);
        }

        return res;
    }
};