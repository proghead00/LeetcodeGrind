class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
      
    if (!root)
      return res;
      
    queue<TreeNode *> q;

    q.push(root);
    q.push(NULL); // NULL acts as a barrier between levels

    vector<int> v;
    while (!q.empty()) {
      TreeNode *temp = q.front();

      if (temp) {
        v.push_back(temp->val);
        q.pop();

        // when I am popping out the current parent, I need to add the children to the queue
          
        if (temp->left)
          q.push(temp->left);
        if (temp->right)
          q.push(temp->right);
          
      } else {
          
        // i.e when the node is NULL, I am at the end of a level
        res.push_back(v); // push the current level to the result
        v.clear();
        q.pop(); // pop the barrier (NULL)
    
        // CORNER CASE:
          
        // let's say the queue is:
        // 1̶ N̶U̶L̶L̶ 2̶ 3̶ N̶U̶L̶L̶ 4̶ 5̶ 6̶ N̶U̶L̶L̶ 7 NULL
        // 1̶ N̶U̶L̶L̶ 2̶ 3̶ N̶U̶L̶L̶ 4̶ 5̶ 6̶ N̶U̶L̶L̶ 7̶ NULL
        // now, we got NULL at front(), BUT WE CANNOT ADD A NEW NULL IN QUEUE
        // so if we pop out this NULL, the queue becomes empty and we DO NOT add
        // a new NULL
        if (!q.empty())
          q.push(NULL);
      }
    }
    return res;
  }
};
