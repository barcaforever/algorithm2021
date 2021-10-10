// 仅仅反转字母

// 双指针

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {

            // 遇到 非 大小写字母，就跳过。
            while (i < n && !(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z')){
                i++;
            }
            while (j >= 0 && !(s[j] >= 'a' && s[j] <= 'z') && !(s[j] >= 'A' && s[j] <= 'Z')){
                j--;
            }

            if (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};