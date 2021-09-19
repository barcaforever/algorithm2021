// 括号生成

// 要生成n个左括号和右括号，那么递归n次，生成左括号；同时，只要右括号数量少于左括号，生成右括号，直到左右括号数都等于n，停止递归；

class Solution {
public:
    vector<string> res;

    void generate(int left, int right, int n, string s) {
        if (left == n && right == n) {
            res.push_back(s);
            return;
        }

        if (left < n) {
            generate(left + 1, right, n, s + "(");
        }
        if (right < left) {
            generate(left, right + 1, n, s + ")");
        }
    }

    vector<string> generateParenthesis(int n) {
        generate(0, 0, n, "");

        return res;
    }
};