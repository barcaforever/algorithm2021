// 最近公共祖先

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 递归

        // 终止条件：root之下再无其他节点
        if (root == NULL) {
            return NULL;
        }

        // 只要是当前层p,q在根节点，那么当前层的公共祖先就是p或q
        if (root == p || root == q) {
            return root;
        }

        // 分别递归寻找左右子树的公共祖先
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // p或q的一个祖先在右子树
        if (left == NULL){
            return right;
        }
        // p或q的一个祖先在左子树
        if (right == NULL){
            return left;
        }
        // p或q的祖先分别在左右子树
        if (left&&right){
            return root;
        }
        return NULL;

        
    }
};