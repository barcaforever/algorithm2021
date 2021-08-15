// 429 N叉树的层序遍历

// 队列存储

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
    
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> res;
        deque<Node*> worker;
        worker.push_back(root);

        while (worker.size()) {
            vector<int> child_vec;
            int loops = worker.size();
            while (loops--) {
                root = worker.front(), worker.pop_front();
                for (auto &i : root->children) {
                    worker.push_back(i);
                }
                child_vec.push_back(root->val);
            }
            res.push_back(child_vec);
        }
        return res;
        
    }
};