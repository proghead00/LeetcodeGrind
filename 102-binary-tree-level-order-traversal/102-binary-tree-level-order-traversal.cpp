class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (!root) return ans;

		// null denotes barrier
		queue<TreeNode* > q;
		q.push(root);
		q.push(NULL);

		vector<int> temp;

		while (!q.empty()) {
			TreeNode* ff = q.front();
			q.pop();

			if (ff) {
				// I wont push NULL in the vector ofc:: NULL will be inside QUEUE (TreeNode* data type)
				temp.push_back(ff->val);
				if (ff->left) q.push(ff->left);
				if (ff->right) q.push(ff->right);
			}
			else {
				// cur node is NULL, so we push the previous NOT NULLs into final ans
				ans.push_back(temp);
				temp.clear();

				// corner case
				if (!q.empty())
					q.push(NULL);
			}

		}
		return ans;
	}
};
