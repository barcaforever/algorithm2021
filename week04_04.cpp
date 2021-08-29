// 33 搜索旋转排序数组

// [4,5,6,7,0,1,2] target=0
// [4,5,6] [7,0,1,2] // mid = 7 n[0] = 4 < 7 ,所以左半边有序;但 4 > 0,所以在 右半边找；以此类推，最终找到了 0；
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int tag = -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[0] <= nums[mid]) { // 左半边有序

                // 如果 target刚好也在左半边有序的这个序列里，就在这里找；
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                }else {
                    // 否则去另一侧无序的里找；
                    left = mid + 1;
                }
            }else {
                // 右半边有序

                // target 在 mid 到 right 之间， left 右移；
                if (target <= nums[right] && target > nums[mid]) {
                    left = mid + 1;
                }else {
                    right = mid - 1;
                }

            }
            
        }
        return tag;
    }
};