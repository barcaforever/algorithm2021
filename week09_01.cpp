// 数组的相对排序

// arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]

// 题目要求arr2 不超过1000，所以建一个1001大小的词频数组，先遍历arr1, 按数字顺序存放每个数字出现的次数；
// 再遍历arr2，按照在arr1里出现的次数，装进结果数组里。如果还有在1不在2里的，按升序和出现次数放进结果数组里。


class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        int freq[1001] = {0};
        for (auto num: arr1) {
            freq[num] ++;
        }
        for (int i = 0; i < arr2.size(); i++) {
            while (freq[arr2[i]]) {
                res.push_back(arr2[i]);
                freq[arr2[i]]--;
            }
        }

        for (int i = 0; i < 1001; i++) {
            while (freq[i]) {
                res.push_back(i);
                freq[i]--;
            }
        }

        return res;
    }
};