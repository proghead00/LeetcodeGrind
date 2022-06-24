class Solution {
public:
	void help(string s, int idx, vector<string> &ans) {
		if (idx == s.size()) {
			ans.push_back(s);
			return;
		}

		if (isdigit(s[idx])) {
			help(s, idx + 1, ans);
		}

		// convert
		if (isalpha(s[idx])) {
			s[idx] = toupper(s[idx]);
			help(s, idx + 1, ans);


			s[idx] = tolower(s[idx]);
			help(s, idx + 1, ans);

		}
	}


	vector<string> letterCasePermutation(string s) {
		vector<string> ans;
		help(s, 0, ans);
		return ans;
	}
};

