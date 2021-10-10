// 最长回文子串

class Solution {
public:
    int left = 0;
    int right = 0;
    int maxlength = 0;
    string longestPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            extend(s, i, i, s.size()); // 单独从当前位置扩展
            extend(s, i, i + 1, s.size()); // 从当前和下一个位置扩展 
        }
        return s.substr(left, maxlength); // 截取最大子串

    }

    // 更新回文子串最大长度和起终点
    void extend (string s, int i, int j, int n) {
        while (i >= 0 && j < n && s[i] == s[j]) {
            if (j - i + 1 > maxlength) {
                maxlength = j - i + 1;
                left = i;
                right = j;
            }
            i--;
            j++;
        }
    }

    
};