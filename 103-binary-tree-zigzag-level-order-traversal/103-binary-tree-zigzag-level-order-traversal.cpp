class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> q;

        q.push(root);
        string dir = "LR";
        while (!q.empty()) {
            int sz = q.size(); // holds the current size, so when we insert children, it won't cause an issue

            vector<int> temp;
            for (int i = 0; i < sz; i++) {

                // push the children
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);

                temp.push_back(q.front()->val);
                q.pop();
            }

            if (dir == "RL") reverse(temp.begin(), temp.end());

            if (dir == "LR") dir = "RL";
            else if (dir == "RL") dir = "LR";

            ans.push_back(temp);
        }

        return ans;

    }
};