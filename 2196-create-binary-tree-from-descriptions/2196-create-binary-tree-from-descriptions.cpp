class Solution {
public:
  TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
    unordered_map<int, TreeNode *> parentMap;
    map<int, pair<int, int>> m;

    for (auto &desc : descriptions) {
      int parent = desc[0];
      int child = desc[1];
      bool isLeft = desc[2];

      if (m.find(parent) == m.end())
        m[parent] = {1, 0};
      else
        m[parent].first = 1;

      if (m.find(child) == m.end())
        m[child] = {0, 1};
      else
        m[child].second = 1;

      if (parentMap.count(parent) == 0) { // check if parent already exists
        parentMap[parent] = new TreeNode(parent);
      }

      TreeNode *root = parentMap[parent];
      if (isLeft) {
        if (parentMap.count(child) == 0) {
          parentMap[child] = new TreeNode(child);
        }
        root->left = parentMap[child]; // connect child to parent
      } else {
        if (parentMap.count(child) == 0) {
          parentMap[child] = new TreeNode(child);
        }
        root->right = parentMap[child]; // connect child to parent
      }
    }

    TreeNode *root;

    for (auto x : m) {
      if (x.second.first == 1 and x.second.second == 0) {
        return parentMap[x.first];
      }
    }
    return root;
  }
};
