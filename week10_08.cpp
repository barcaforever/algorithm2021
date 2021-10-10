// 字符串转换整数 atoi

class Solution {
public:
    int myAtoi(string s) {
        if (s.size() == 0) return 0;
        int index = 0;
        int minus = 1;
        int len = s.size();

        // 遇到空格 后移
        while (s[index] == ' ') {
            index++;
        }

        // 1.遍历完空格后就到了末尾，2.非数字，非 + - 均直接返回
        if (index == len || (!isdigit(s[index])) && s[index] != '-' && s[index] != '+') {
            return 0;
        }

        // - 取 负号
        if (s[index] == '-') {
            minus = -1;
            index++;
        }else if (s[index] == '+') {
            // + 取正号
            index++;
        }

        long num = 0;
        while (index < len && isdigit(s[index])) {
            // 10进制 取出 最终的数字
            num = num * 10 + (s[index] - '0');
            index++;

            if (num > INT_MAX){
                if (minus == 1) {
                    return INT_MAX;
                }
                if (minus == -1) {
                    return INT_MIN;
                }
            }
        }
        return num * minus;
    }
};