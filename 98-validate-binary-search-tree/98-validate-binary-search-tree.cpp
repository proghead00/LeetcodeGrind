class Solution {
public:
  bool help(TreeNode* root, long long mx, long long mn) {
    if (!root) return true;

    if (root->val >= mx or root->val <= mn) return false;

    bool left =  help(root->left, root->val, mn);
    bool right = help(root->right, mx, root->val);

    return left and right;
  }


  bool isValidBST(TreeNode* root) {
    return help(root, LLONG_MAX, LLONG_MIN);
  }
};
