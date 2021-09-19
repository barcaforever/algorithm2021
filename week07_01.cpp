// 爬楼梯

// 爬1级 1种方案，爬2级2种方案,爬3级的方案就等于爬1级的方案与爬2级的方案之和；（因为可以从1级台阶跨2步直接到3级，也可以2级台阶跨1步直接到3级）
// 由此类推，2级台阶以后的第n级的方案数 是 爬（n-1）级方案数和爬（n-2）级方案数之和；

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int f1 = 1, f2 = 2;
        for (int i = 3; i <= n; i++) {
            int f3 = f1 + f2;
            f1 = f2;
            f2 = f3;

        }

        return f2;
    }
};