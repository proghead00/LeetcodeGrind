class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root)
      return res;
    queue<TreeNode *> q;

    q.push(root);
    q.push(NULL); // acts as a barrier between levels

    vector<int> v;
    while (!q.empty()) {
      TreeNode *temp = q.front();

      if (temp) {
        v.push_back(temp->val);
        q.pop();
        if (temp->left)
          q.push(temp->left);
        if (temp->right)
          q.push(temp->right);
      } else {
        res.push_back(v);
        v.clear();
        q.pop();

        if (!q.empty())
          q.push(NULL);
      }
    }
    return res;
  }
};
