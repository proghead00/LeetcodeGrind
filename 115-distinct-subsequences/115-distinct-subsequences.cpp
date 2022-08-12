class Solution {
public:
  int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    int mod = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n ; i++) {
      for (int j = 0; j <= m; j++) {

        if (j == 0) dp[i][j] = 1;
        else if (i == 0) dp[i][j] = 0;

        else {
          if (s[i - 1] == t[j - 1]) {
            dp[i][j] = (dp[i - 1][j - 1] % mod  + dp[i - 1][j] % mod) % mod;
          }
          else {
            dp[i][j] = dp[i - 1][j];
          }
        }
      }
    }

    return dp[n][m] % mod;
  }
};