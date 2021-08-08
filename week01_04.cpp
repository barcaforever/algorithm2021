// 88 合并两有序数组

// 思路： 从两数组末尾数字开始，互相比较，取较大值 ，放在原数组的末尾；
// 接着较大值的前一个值比较，以此类推；

#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int tail = m + n - 1;
        int cur;
        while (p1 >= 0 || p2 >= 0){
            if (p1 == -1){
                cur = nums2[p2--];
            }else if (p2 == -1){
                cur = nums1[p1--];
            }else if (nums1[p1] > nums2[p2]){
                cur = nums1[p1--];
            }else{
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
        

    }
};