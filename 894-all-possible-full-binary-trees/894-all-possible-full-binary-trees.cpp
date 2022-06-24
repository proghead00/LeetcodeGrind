class Solution {
public:
	unordered_map <int, vector<TreeNode*>> mp;

	vector<TreeNode*> allPossibleFBT(int n) {
		vector<TreeNode*> ans;

		if (n < 1 or n % 2 == 0) return ans;

		mp[0] = {};
		mp[1] = {new TreeNode(0)};

		if (mp.count(n)) return mp[n];

		for (int i = 1; i < n; i += 2) {
			vector <TreeNode *> leftSub = allPossibleFBT(i);           // store all the left nodes in leftSub
			vector <TreeNode *> rightSub = allPossibleFBT(n - i - 1);  // store all the remaining n-i-1 right nodes in rightSub

			for (auto ll : leftSub) {
				for (auto rr : rightSub) {
					TreeNode *root = new TreeNode(0, ll, rr); // makes a node and links its left and right children
					ans.push_back(root);
				}
			}
		}
		return mp[n] = ans;

	}
};