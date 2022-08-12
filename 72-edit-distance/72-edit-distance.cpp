class Solution {
public:

  int minDistance(string s1, string s2) {
    // write you code here
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (i == 0) dp[i][j] = j;
        else if (j == 0) dp[i][j] = i;

        else {
          if (s1[i - 1] == s2[j - 1])
            dp[i][j] = dp[i - 1][j - 1];

          else {
            int ins = dp[i - 1][j];
            int del = dp[i][j - 1];
            int rep = dp[i - 1][j - 1];
            dp[i][j] = 1 + min(ins, min(del, rep));
          }
        }
      }
    }

    return dp[n][m];
  }
};
