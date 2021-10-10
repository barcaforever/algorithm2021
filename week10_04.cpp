// 翻转字符串单词 III

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return s;

        // 用数组处理原字符串，将其存在数组中，做后续处理
        s += ' ';
        vector<string> res;
        string tmp;
        for (char c : s) {
            if (c == ' ') {
                res.push_back(tmp);
                tmp.clear();
            }else {
                tmp += c;
            }
        }
        s.clear();

        string ans;
        for (string r : res) {
            // 在数组中反转每个单词，再拼接空串和单词
            reverse(r.begin(), r.end());
            ans += r;
            ans += ' ';
            
        }

        ans.pop_back(); // 去掉最后一个空字符串

        return ans;
    }
};