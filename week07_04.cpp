// 单词接龙

// 将list的单词存入set，加快查询速度
// 新建一个队列，存入beginWord;每次接龙新的单词之前，弹出当前的单词。
// 新建一个map,存储当前单词经过接龙的次数；
// 开始接龙：每次修改一个字母，同时跟set里的单词比对，只要在set里同时又不在map，则接龙次数+1；如果刚好等于endWord,结束，返回接龙次数；

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 转化成set 查询更快
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        unordered_map<string, int> visitedMap; // <word, word的长度>

        // bfs 初始化队列
        queue<string> que;
        que.push(beginWord); // (beginword)

        // 初始化map
        visitedMap.insert(pair<string, int>(beginWord, 1));

        while (!que.empty()) {
            string word = que.front();
            que.pop();

            int path = visitedMap[word];
            for (int i = 0; i < word.size(); i++) {
                string newWord = word; // 用新单词置换word，因为每次要置换其中一个字母;
                // 遍历这个word，给每个位置都换一次字母，如果 替换后的单词 在set 且没被 map 访问过，
                // 存到map,加到que中
                for (int j = 0; j < 26; j++) {
                    newWord[i] = j + 'a';
                    if (newWord == endWord) return path + 1;
                    if (wordSet.find(newWord) != wordSet.end() && visitedMap.find(newWord) == 
                    visitedMap.end()) {
                        visitedMap.insert(pair<string, int>(newWord, path + 1));
                        que.push(newWord);
                    }

                }

            }
        }
        return 0;
    }
};