// 最小基因变化

// 分别将头尾基因放入set；
// 从头基因开始，里面每个字母分别用A，C，G，T替换，每次替换次数+1；
// 替换到刚好和尾基因相等，则返回替换次数；否则继续循环；直到和尾基因相等。
// 每次循环都从head和tail里更小的那个集合进行。

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> bankSet;
        for (string& b : bank) {
            bankSet.insert(b);
        }

        if (bankSet.find(end) == bankSet.end()) {
            return -1;
        }

        char replace[4] = {'A', 'C', 'G', 'T'};

        unordered_set<string> heads = {start};
        unordered_set<string> tails = {end};

        unordered_set<string> temp; // 保存当前集合

        int rounds = 0;

        while (!heads.empty() && !tails.empty()) {
            // 进循环就 ++
            ++rounds;

            // 取更小的那个set 进行循环遍历；
            if (heads.size() > tails.size()) {
                swap(heads, tails);
            }

            for (const string& head : heads) {
                string cur = head;

                int n = cur.size(); // 遍历 cur 的每个字符

                for (int i = 0; i < n; i++) {
                    char old = cur[i];
                    for (int j = 0; j < 4; j++) {
                        cur[i] = replace[j]; // 替换 四种 字符
                        if (tails.find(cur) != tails.end()) {
                            return rounds;
                        }
                        if (bankSet.find(cur) != bankSet.end()) {
                            bankSet.erase(cur);
                            temp.insert(cur);
                        }
                    }
                    cur[i] = old;
                }

            }

            swap(heads, temp);
            temp.clear();

        }
        return -1;

    }
};