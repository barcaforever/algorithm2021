// 翻转字符串的单词

// s = "the sky is blue" 输出："blue is sky the"

// 先去掉s头部和尾部可能的多余空格（" hello world " --> "hello world"）再整体翻转，变成"eulb si yks eht" 再每个单词单独翻转 "blue is sky the"


class Solution {
public:
    void removeExtraSpaces(string &s) {
        int slowIndex = 0, fastIndex = 0;

        // 如果字符串最前端是空格，用fastIndex去除掉
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }

        for (; fastIndex < s.size(); fastIndex++) {
            // 去掉中间空格，slowIndex就是fastIndex-空格数
            if (fastIndex - 1 > 0 && s[fastIndex - 1] == s[fastIndex] && s[fastIndex] == ' ') {
                continue;
            }else {
                s[slowIndex++] = s[fastIndex];
            }
        }

        // 去掉字符串末尾的空格
        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') {
            s.resize(slowIndex - 1);
        }else {
            s.resize(slowIndex);
        }
    }
            // 翻转字符串 左闭右闭
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    string reverseWords(string s) {
        removeExtraSpaces(s); // 去掉前后空格；
        reverse(s, 0, s.size() - 1);
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            while (j < s.size() && s[j] != ' ') j++;
            reverse(s, i, j - 1);
            i = j;
        }
        return s;
    }
};