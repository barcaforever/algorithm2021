// 位1的个数

// 规律 n & n - 1 按位与，会将最后一个1变成0，
// 最终 n 会经过几次&的操作变成0，操作的次数就等于n中所含的1的个数。

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            res += 1;
            n &= n - 1;
        }
        return res;
    }
};