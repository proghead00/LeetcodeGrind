class Solution {
public:

  int help(string &s1, string &s2, int i, int j,  vector<vector<int>> &dp) {

    if (i == 0 or j == 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i - 1] == s2[j - 1]) return dp[i][j] = 1 + help(s1, s2, i - 1, j - 1, dp);

    else return dp[i][j] = max(help(s1, s2, i - 1, j, dp), help(s1, s2, i, j - 1, dp));

  }

  int longestCommonSubsequence(string text1, string text2) {
    int sz1 = text1.size();
    int sz2 = text2.size();

    vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1, -1));

    return help(text1, text2, text1.size(), text2.size(), dp);
  }
};