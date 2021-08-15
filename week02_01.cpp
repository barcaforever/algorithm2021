// 有效的字母异位词

// 本题采用类似位运算的思路，利用字母的ascii码值是固定的特点，创建一个26个数字大小的数组，
// 在第一个字符串每个字母出现时，将每个字母对应的ascii码值（这里是利用了与a的值的大小对比，做了简化）+1；
// 遍历完第一个字符串后，遍历第二个，出现了就-1；
// 那么，如果字符串互为异位词，则最终数组为26个0.否则就不是；

#include <string.h>;

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