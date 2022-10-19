
class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {

    if (!root) return NULL;

    // go to each level and swap
    swap(root->left, root->right);

    TreeNode* ll = invertTree(root->left);
    TreeNode* rr = invertTree(root->right);

    return root;

  }
};