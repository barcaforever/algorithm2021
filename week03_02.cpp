// 从前序和中序遍历序列构造二叉树

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
public:
    TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd,vector<int>& preorder,int preorderBegin, int preorderEnd) {
        // 递归 终止条件: 前序数组全部切割完毕，即begin==end
        if (preorderBegin == preorderEnd) return nullptr;

        // 前序遍历的第一个值，就是用来 切割中序数组 的值
        int rootValue = preorder[preorderBegin]; 
        
        TreeNode* root = new TreeNode(rootValue);

        if (preorderEnd == preorderBegin + 1) return root;

        int sliceIndex; // 找到前序的值在中序中的位置
        for (sliceIndex = inorderBegin; sliceIndex < inorderEnd; sliceIndex++) {
            if (inorder[sliceIndex] == rootValue) {
                break;
            }
        }

        // 切割中序数组
        int inorderLeftBegin = inorderBegin;
        int inorderLeftEnd = sliceIndex;

        int inorderRightBegin = sliceIndex + 1;
        int inorderRightEnd = inorderEnd;

        // 切割前序
        int preorderLeftBegin = preorderBegin + 1; // 要把前序的第一个数字去掉
        int preorderLeftEnd = preorderBegin + 1 + sliceIndex - inorderBegin;

        // 终止位置是起始位置加上中序左区间的size
        int preorderRightBegin = preorderBegin + 1 + (sliceIndex - inorderBegin);
        int preorderRightEnd = preorderEnd;

        // 递归切割
        root->left = traversal(inorder, inorderLeftBegin, inorderLeftEnd, preorder,preorderLeftBegin, preorderLeftEnd);
        root->right = traversal(inorder, inorderRightBegin, inorderRightEnd, preorder,
preorderRightBegin, preorderRightEnd);

        return root; 

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.size() == 0 || preorder.size() == 0) return nullptr;

        return traversal(inorder, 0, inorder.size(), preorder, 0, preorder.size());
        // 参数左闭右开原则

    }
};