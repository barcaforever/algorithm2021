// Leetcode 26 删除有序数组里的重复项

// 思路：双指针
// [0,0,0,1,1,1,2,2,2,2,2]

// 指针p 指向0；指针q 指向1；
// 指向的数如果相等，则q+1；以此类推；
// 否则，p+1,把q位置的值赋给p；以此类推；
// p 走到数组最后一个位置，循环结束；

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int p = 0, q = 1;
        while (q < nums.size()) {
            if (nums[p] == nums[q]) {
                q++;
            } else {
                nums[++p] = nums[q];
            }
        }
        return p + 1;
        
    }
};