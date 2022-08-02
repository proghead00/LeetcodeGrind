class Solution {
public:

	void help(int n, string &temp, vector<string> &ans, int open, int close) {
		if (temp.size() == 2 * n) {
			if (close == n and open == n) ans.push_back(temp);
			return;
		}

		if (open < n) {
			temp.push_back('(');
			help(n, temp, ans, open + 1, close);
            
            // almost forgot to BACKTRACK ughhh:
			temp.pop_back();
		}

		if (close < open) {
			temp.push_back(')');
			help(n, temp, ans, open, close + 1);
			temp.pop_back();
		}
	}

	vector<string> generateParenthesis(int n) {

		vector<string> ans;
		string temp;
		help(n, temp, ans, 0, 0);
		return ans;
	}
};