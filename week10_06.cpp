// 同构字符串

// 输入：s = "egg", t = "add"
// 输出：true

// 解法：双map,互相唯一映射；符合唯一映射则同构；不符合则不是
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // 
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