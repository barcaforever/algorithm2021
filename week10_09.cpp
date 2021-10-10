// 字符串中的所有字母异位词

// 输入: s = "cbaebabacd", p = "abc"
// 输出: [0,6]
// 解释:
// 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
// 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (p.size() > s.size() || s.size() == 0) return ans;
        vector<int> need(128);
        vector<int> windows(128);

        // 异位词原词字母存到一个数组里
        for (char a : p) need[a]++;

        // 做比较的字符串里的字母存到另外一个数组里，但是只存 前（异位词长度-1）个字母
        for (int i = 0; i < p.size() - 1; i++) windows[s[i]]++;

        int l = 0, r = p.size() - 1;
        // 异位词比较 用数组存
        while (r < s.size()) {
            // 从第 （异位词长度）开始存字母
            windows[s[r++]]++;
            // 比较 两数组，相等则说明找到了一对 异位词
            if (windows == need) ans.push_back(l);
            // 删掉最小下标位置处的字母，
            // 往后循环存入下一个字母,开始新一轮比较；
            windows[s[l++]]--;
        }
        return ans;
    }
};