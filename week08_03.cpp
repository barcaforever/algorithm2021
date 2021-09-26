// 颠倒二进制位


// 如果要颠倒一个十进制数，比如x = 123，变成321，那么 公式为 y = y * 10 + x % 10 ; x = x / 10;
// 二进制同理，公式为 y = y * 2 + x % 2, x = x / 2 ; 32位的二进制，需要循环32次；
// * 2 用左移，/ 2 用右移； 
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res = (res << 1) + (n & 1);
            n >>= 1;
        }
        return res;
        
    }
};