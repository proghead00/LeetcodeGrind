class Solution {
public:
    vector<int> help(string s, int start, int end) {
        vector<int> ans;
        int isNum = 1;

        for (int i = start; i <= end; i++) {
            if (s[i] == '-' or s[i] == '+' or s[i] == '*') {
                isNum = 0;
                vector<int> left = help(s, start, i - 1);
                vector<int> right = help(s, i + 1, end);

                for (auto l : left) {
                    for (auto r : right) {
                        if (s[i] == '-')
                            ans.push_back(l - r);
                        else if (s[i] == '+')
                            ans.push_back(l + r);
                        else if (s[i] == '*')
                            ans.push_back(l * r);
                    }
                }
            }

        }

        if (isNum)
            ans.push_back(stoi(s.substr(start, end - start + 1)));
        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return help(expression, 0, expression.size() - 1);
    }
};
