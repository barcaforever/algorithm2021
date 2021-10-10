// 翻转字符串里的单词

// 用双指针，速度更快
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
        removeExtraSpaces(s);
        cout << s << endl;
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