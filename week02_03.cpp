// 589 n叉树前序遍历 
// 用到了深度优先搜索

#include <vector>

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> res;
    void dfs_travel(Node* cur) {
        if (cur == NULL){
            return;
        }

        res.emplace_back(cur->val);
        for (auto c:cur->children) {
            dfs_travel(c);
        }
    }
    vector<int> preorder(Node* root) {
        if (root != NULL) {
            dfs_travel(root);
        }
        return res;
    }
};