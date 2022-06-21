class Solution {
public:

  int s = 0;
  TreeNode* bstToGst(TreeNode* root) {
    if (!root) return NULL;

    bstToGst(root->right);

    s += root->val;
    root->val = s;

    bstToGst(root->left);


    return root;

  }
};