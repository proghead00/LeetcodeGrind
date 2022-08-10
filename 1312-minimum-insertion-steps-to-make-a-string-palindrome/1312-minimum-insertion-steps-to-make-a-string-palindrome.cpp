class Solution {
public:


  int minInsertions(string s) {
    string rev = s;
    reverse(s.begin(), s.end());

    int n = s.size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        if (i == 0 or j == 0) dp[i][j] = 0;

        else {
          if (s[i - 1] == rev[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
          else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return n - dp[n][n];
  }
};