// 移动零 [0,1,0,3,12] ==> [1,3,12,0,0]

#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            
            if (nums[i] != 0){
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
                j++;
                // 如果数组中有0，那么j 位肯定是0；
                // j 记录的是下一个非0元素的位置；
            }
        }
        
    }
};