
class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {

    if (!root) return NULL;

    // go to each level and swap
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    TreeNode* ll = invertTree(root->left);
    TreeNode* rr = invertTree(root->right);

    return root;

  }
};