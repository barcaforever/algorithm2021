// [1,2,3,4,5,6,7] k = 3 ==> [5,6,7,1,2,3,4]

// 思路1 ：整体旋转后 再前后分开旋转

#include <vector>
using namespace std;

class Solution {
public:

    void reverse(vector<int>& nums, int start, int end){
        while (start < end) {
            swap(nums[start], nums[end]);
            start += 1;
            end -= 1;
        }

    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);

    }
};