class Solution {
public:
  int helper(string &s1, string &s2, int n, int m, vector<vector<int>> &dp) {
    if (dp[n][m] != -1)
      return dp[n][m];

    if (!n)
      return dp[n][m] = m;
    if (!m)
      return dp[n][m] = n;

    // s1 = satur
    // s2 = sun
    // insert => satur(n), su(n) => n, m-1
    // delete => satur, sun => n-1, m
    // replace => satun, sun => n-1, m-1
    if (s1[n - 1] == s2[m - 1])
      return dp[n][m] = helper(s1, s2, n - 1, m - 1, dp);

    int ins = helper(s1, s2, n - 1, m, dp);
    int del = helper(s1, s2, n, m - 1, dp);
    int rep = helper(s1, s2, n - 1, m - 1, dp);
    return dp[n][m] = 1 + min(ins, min(del, rep));
  }
    
  int minDistance(string str1, string str2) {
    // write you code here
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    return helper(str1, str2, n, m, dp);
  }
};
