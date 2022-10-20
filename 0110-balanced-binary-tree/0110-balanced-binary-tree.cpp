class Solution {
public:
    int help(TreeNode* root) {
        if (!root) return 0;

        int lh = help(root->left);
        int rh = help(root->right);

        if (abs(lh - rh) > 1) return -1;
        if (lh == -1 or rh == -1) return -1;

        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode* root) {
        return help(root) != -1;
    }
};