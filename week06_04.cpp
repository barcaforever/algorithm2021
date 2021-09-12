// 任务调度器

// [AAAAABBBBBCCDD] n = 2

// 每列都有最多的那个元素，之间间隔N 
// A \B \C \
// A \B \C \
// A \B \D \
// A \B \D \
// A \B \x \

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> tmp(26);
        int t = tasks.size();
        int maxM = 0; // 最多的一个任务的次数；
        int countMax = 0; // 最多次数的任务数量；

        for (char c : tasks) {

            // 统计出现的元素的次数
            tmp[c - 'A']++;
            // 更新最大次数；
            maxM = max(tmp[c-'A'], maxM);
        }

        for (int i = 0; i < tmp.size(); i++) {
            // 更新出现次数最多的任务数；
            if (tmp[i] == maxM) {
                countMax++;
            }
        }

        // 以最多的那个任务为基准，间隔N个位置，把其余的任务安插进去。
        return max(t, (maxM-1)*(n+1)+countMax);

    }
};