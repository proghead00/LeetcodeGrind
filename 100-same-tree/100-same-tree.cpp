class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p and !q) return true;
        if (!p and q) return false;
        if (p and !q) return false;
        
        // it's confirmed that neither of them contains NULL, hence there's a value associated
        if (p->val != q->val) return false;


        return (isSameTree(p->left, q->left) & isSameTree(p->right, q->right));
    }
};