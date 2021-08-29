// 153 寻找旋转排序数组中的最小值

// 二分查找;
// 如果中间的数比右边的大，说明最小值在mid右半边；
// 如果中间的数比右边的小，说明最小的数在mid或者mid左半边；

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2 ;
            if (nums[mid] < nums[right]) {
                right = mid ;
            }else {
                left = mid + 1;
            }
        }
        return nums[left - 1];
    }
};