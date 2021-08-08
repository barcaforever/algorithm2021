// 66 加一 

// 考虑几种情况：全部是9，那么加一后，需要新开一个数组，位数是原数组+1，在第一位给到1即可；
// 当有9存在，需要进一位，那么就一直进到不为9存在的时候为止；返回+1后的数组；

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        for (int i = length - 1; i >= 0; i --){
            digits[i]++;
            digits[i] %= 10;
            if (digits[i] != 0){
                return digits;
            }
        }
        vector<int> res(length + 1); 
        res[0] = 1;
        return res;

    }
};