
class Solution {
public:

	// hd == horizontal distances: ...,-2,-1,0,1,2,...

	void help(TreeNode* root, int hd, int levels, map<int, map<int, multiset<int>>> &mp) {
		if (!root) return;

		help(root->left, hd - 1, levels + 1, mp);
		help( root->right, hd + 1, levels + 1, mp);

		// hd maps to levels, and levels in-turn to the node values
		mp[hd][levels].insert(root->val);
	}

	vector<vector<int>> verticalTraversal(TreeNode* root) {

		// map::hd --> map:: levels, elements
		map<int, map<int, multiset<int>>> mp;

		help(root, 0, 0, mp);

		vector<vector<int>> ans;

		vector<int> temp;
		for (auto &x : mp) {
			for (auto &y : x.second) {
				for (auto &z : y.second) temp.push_back(z);
			}
			ans.push_back(temp);
			temp.clear();
		}

		return ans;
	}
};
