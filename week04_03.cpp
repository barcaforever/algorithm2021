// 455 分发饼干 

// 孩子胃口【1,2】饼干大小[1,2,3]

// 从胃口最大的孩子开始，用最大的饼干匹配，匹配到就记数+1；然后就继续循环，去匹配下一位孩子，以及之前匹配到的饼干的下一块饼干，匹配到就+1；
// 
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1;
        int result = 0;
        for (int i = g.size() - 1; i >= 0; i--) {
            if (index >= 0 && s[index] >= g[i]) {
                result++;
                index--;
            }
        }
        return result;

    }
};