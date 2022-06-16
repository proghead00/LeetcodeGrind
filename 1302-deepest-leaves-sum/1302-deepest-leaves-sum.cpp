class Solution {
public:
  void help(TreeNode *root, int depth, int deepest, int ans,
            multimap<int, TreeNode *> &mp) {

    if (!root) {
      return;
    }
    if (!root->left and !root->right) {
      mp.insert({depth, root});
    }
    help(root->left, depth + 1, deepest, ans, mp);
    help(root->right, depth + 1, deepest, ans, mp);
  }

  int deepestLeavesSum(TreeNode *root) {
    int ans = 0;
    multimap<int, TreeNode *> mp;
    help(root, 0, 0, ans, mp);

    int mx = INT_MIN;
    for (auto x : mp) {
      mx = max(mx, x.first);
    }
    for (auto x : mp) {
      if (x.first == mx) {
        ans += x.second->val;
      }
    }
    return ans;
  }
};
