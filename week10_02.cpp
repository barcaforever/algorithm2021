// 反转字符串ii

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            // 剩余字符大于k ，翻转前k个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
                continue;
            }

            // s.size() - i < k 剩余字符少于k个，则全部反转，范围从【i， s.size()】
            reverse(s.begin() + i, s.begin() + s.size());
        }
        return s;
    } 
};