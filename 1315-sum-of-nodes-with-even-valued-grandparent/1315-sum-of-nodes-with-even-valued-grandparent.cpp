class Solution {
public:
  int ans = 0;

  void help(TreeNode *root) {
    if (!root)
      return;

    if (root->val % 2 == 0) {
      if (root->left) {
        if (root->left->left)
          ans += root->left->left->val;
        if (root->left->right)
          ans += root->left->right->val;
      }
      if (root->right) {
        if (root->right->left)
          ans += root->right->left->val;
        if (root->right->right)
          ans += root->right->right->val;
      }
    }

    help(root->left);
    help(root->right);
  }

  int sumEvenGrandparent(TreeNode *root) {
    help(root);
    return ans;
  }
};
