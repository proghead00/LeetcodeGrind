class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		queue<TreeNode*> q;

		if (!root) return ans;

		vector<int> temp;
		q.push(root);
		while (!q.empty()) {
			int sz = q.size();
			for (int i = 0; i < sz; i++) {

				TreeNode* ff = q.front();
				q.pop();

				// insert the children
				if (ff->left)
					q.push(ff->left);

				if (ff->right)
					q.push(ff->right);

				temp.push_back(ff->val);
			}
			ans.push_back(temp);
            temp.clear();
		}

		return ans;
	}
};