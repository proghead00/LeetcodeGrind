#include <bits/stdc++.h>
int lcs(string s1, string s2, int m, int n, vector<vector<int>> &dp) {

  // dimension of dp is m+1 and n+1

  for (int i = 0; i < m + 1; i++)
    dp[i][0] = 0;
  for (int i = 0; i < n + 1; i++)
    dp[0][i] = 0;

  for (int i = 1; i < m + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (s1[i - 1] == s2[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[m][n];
}
int longestPalindromeSubsequence(string str) {
  // Write your code here.
  int n = str.size();
  string rev = string(str.rbegin(), str.rend());
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  return lcs(str, rev, n, n, dp);
}
