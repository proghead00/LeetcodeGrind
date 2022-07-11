class Solution {
public:
	vector<int> ans;

	void help(TreeNode* root, int level) {
		if (!root) return;

		if (ans.size() == level) ans.push_back(root->val);

		help(root->right, level + 1);
		help(root->left, level + 1);
	}

	vector<int> rightSideView(TreeNode* root) {

		help(root, 0);
		return ans;
	}
};