class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p and !q) return true;
        if (!p and q) return false;
        if (p and !q) return false;

        if (p->val != q->val) return false;

        return (isSameTree(p->left, q->left) & isSameTree(p->right, q->right));
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot and root) return true;
        if (!root and subRoot) return false;

        if (isSameTree(root, subRoot)) return true;

        return (isSubtree(root->left, subRoot) or (isSubtree(root->right, subRoot)));
    }

};