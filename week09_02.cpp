// 有效字母异位词

// s = "anagram", t = "nagaram"

// 新建一个大小为26的数组，存放26个字母（存放的是每个字母相对字母a的ACI码值，是固定的）
// 遍历第一个字符串，在新建数组里，对出现的字母频数进行加法操作，记录最终出现的次数；
// 遍历第二个字符串，对出现的字母频数进行减法操作，如果跟第一个字符串是异位词，那么出现的每个字母次数应该一样，也就会被减到0；
// 如果是异位词，那么频数数组里的每个位置都应该是0，遍历这个数组，检查下是否为0即可

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            record[s[i] - 'a']++;
        }
        for (int j = 0; j < t.size(); j++) {
            record[t[j] - 'a']--;
        }
        for (int i = 0; i < 26; i++){
            if (record[i] != 0) {
                return false;
            }
        }
        return true;
        
    }
};