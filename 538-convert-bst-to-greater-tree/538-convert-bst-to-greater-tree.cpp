class Solution {
public:

  int s = 0;
  TreeNode* convertBST(TreeNode* root) {
    if (!root) return NULL;

    convertBST(root->right);

    s += root->val;
    root->val = s;

    convertBST(root->left);


    return root;

  }
};