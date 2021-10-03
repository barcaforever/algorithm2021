// 最长有效括号

// 输入：s = ")()())"
// 输出：4
// 解释：最长有效括号子串是 "()()"

// 最长括号都是连续的一段段的。所以建立个栈存左括号，建立个start指针，记录有效的括号的开始位置。
// 遍历整个字符串。当栈里为空时，如果遇到右括号，start往后移i+1位。因为不是有效括号。一旦遇到左边的括号，弹入栈中保存。之后再遇到右括号，
// 栈顶弹出一位。假如栈顶弹出后栈为空，记录下此时的start，最大长度加上i+1-start；直到循环结束。最大长度ans不断更新，并记录下来即可。

class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;
        int ans = 0;
        for (int i = 0, start = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(i);
            else {
                if (!st.empty()) {
                    st.pop();
                    if (st.empty()) ans = max(ans, i - start + 1);
                    else ans = max(ans, i - st.top());
                }else {
                    start = i + 1;
                }
            }
        }
        return ans;
    }
};