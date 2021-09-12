// 回文子串 

// a d a c c 
           ||
//       <-i j->

// 双指针i，j，如果同时指向一个字符，那么这个字符肯定是回文；如果s[i]=s[j],且j-i<=2 如a d a 肯定是；
// 如果j-i>2 就要看 i+1位置和j-1位置是否相等了。

class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();

        // 用二维数组 记录 不同位置的回文子串的出现次数
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),0));
        int count = 0;

        // 为了计算i，j位置是否是回文，要先计算 i+1，j-1 位置的，而j=i，所以i倒序遍历；
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i; j < len; j++) {
                if (s[i] != s[j]) continue;

                dp[i][j] = j - i <= 2 || dp[i+1][j-1];

                if (dp[i][j]) count++;
            }
        }


        return count;

    }
};