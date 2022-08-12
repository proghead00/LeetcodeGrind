class Solution {
public:
  int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();

    vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(m + 1, 0));

    for (int i = 0; i <= n ; i++) {
      for (int j = 0; j <= m; j++) {

        if (j == 0) dp[i][j] = 1;
        else if (i == 0) dp[i][j] = 0;

        else {
          if (s[i - 1] == t[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1]  + dp[i - 1][j];
          }
          else {
            dp[i][j] = dp[i - 1][j];
          }
        }
      }
    }

    return dp[n][m];
  }
};