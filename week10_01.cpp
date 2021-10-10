 // 字符串中的第一个唯一字符

class Solution {
public:
    int firstUniqChar(string s) {
        int num[26] = {0};

        // 用数组记录字符出现次数
        for (char &c : s) num[c - 'a']++;

        for (int i = 0; i < s.size(); i++) {
            // 按字符顺序遍历，如果出现次数是1，则是结果，返回下标即可
            if (num[s[i]-'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};

