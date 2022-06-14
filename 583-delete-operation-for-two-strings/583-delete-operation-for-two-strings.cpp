class Solution {
  //   int dp[501][501];

public:
  int help(string &s1, int n, string &s2, int m, vector<vector<int>> &dp) {
    if (n == 0)
      return 0;
    if (m == 0)
      return 0;

    if (dp[n][m] != -1)
      return dp[n][m];

    if (s1[n - 1] == s2[m - 1])
      return dp[n][m] = 1 + help(s1, n - 1, s2, m - 1, dp);
    else
      return dp[n][m] = max(help(s1, n - 1, s2, m, dp), help(s1, n, s2, m - 1, dp));
  }

  int minDistance(string word1, string word2) {
    // memset(dp, -1, sizeof(dp));
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
    int lcs = help(word1, word1.size(), word2, word2.size(), dp);
    return word1.size() + word2.size() - 2 * lcs;
  }
};
