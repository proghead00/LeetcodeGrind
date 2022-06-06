class Solution {
public:
  int real(string &s1, string &s2, int n, int m, vector<vector<int>> &dp) {
    if (dp[n][m] != -1)
      return dp[n][m];

    if (!n or !m)
      dp[n][m] = 0;
    else {
      if (s1[n - 1] == s2[m - 1])
        dp[n][m] = 1 + real(s1, s2, n - 1, m - 1, dp);
      else
        dp[n][m] = max(real(s1, s2, n - 1, m, dp), real(s1, s2, n, m - 1, dp));
    }
    return dp[n][m];
  }

  int longestCommonSubsequence(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return real(s1, s2, n, m, dp);
  }

  string longestPalinSubstring(string str) {
    // Write your code here.

    string rev = reverse(str);
    return (str, rev);
  }
};
