// 同构字符串

// s = "egg", t = "add"

// 用哈希法，新建2个map，构建s和t里每个字母对应的映射。
// 只要每个map里的键值对都是唯一的，就算同构；否则就不算；

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;

        for (int i = 0, j = 0; i < s.size(); i++, j++) {
            if (map1.find(s[i]) == map1.end()) {
                map1[s[i]] = t[j];
            }

            if (map2.find(t[j]) == map2.end()) {
                map2[t[j]] = s[i];
            }

            if (map1[s[i]] != t[j] || map2[t[j]] != s[i]) {
                return false;
            }
        }
        return true;

    }
};