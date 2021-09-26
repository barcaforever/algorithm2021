// 2 的 幂

// 不断地对N 除以2，最终如果结果是1，那么就说明N是2的幂次方
class Solution {
public:
    bool isPowerOfTwo(int n) {

        if (!n) return n;
        while (n % 2 == 0) n >>= 1;
        return n == 1;
    }
};