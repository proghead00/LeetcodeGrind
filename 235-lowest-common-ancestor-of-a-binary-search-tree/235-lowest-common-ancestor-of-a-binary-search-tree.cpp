class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
   
    // find the split
    if(p->val < root->val  and q->val < root->val) return lowestCommonAncestor(root->left, p, q);
    else if(p->val > root->val  and q->val > root->val) return lowestCommonAncestor(root->right, p, q);
    else return root;

  }
};
