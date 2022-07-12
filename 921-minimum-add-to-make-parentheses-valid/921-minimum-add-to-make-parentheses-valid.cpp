class Solution {
public:
	int minAddToMakeValid(string s) {

		int open = 0, close = 0;

		for (int i = 0; i < s.size(); i++) {

			// we can casually insert opening brackets, since we do not know whether we'll have a closing bracket in the future
			if (s[i] == '(') open++;
			else {
				if (open == 0) close++;

				// cancel out the previous opened bracket with the current closing bracket
				else open--;
			}
		}

		return (open + close);

	}
};