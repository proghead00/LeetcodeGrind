class Solution {
public:

  int longestCommonSubsequence(string s1, string s2) {
    int sz1 = s1.size();
    int sz2 = s2.size();

    vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1, 0));

    /*
      1. loop i, j
      2. form the base case
      3. copy the recurrence
    */


    // start from 1 since we'd take out the character with i-1, j-1
    for (int i = 1; i <= sz1; i++) {
      for (int j = 1; j <= sz2; j++) {

        // 1. recursive base case:
        //    if (i == 0 or j == 0) return 0;

        // converting base case to tabulated version:
        if (i == 0 or j == 0) dp[i][j] = 0;

        else {

          // 3. copying the recurrence in tabulated form
          if (s1[i - 1] == s2[j - 1])  dp[i][j] = 1 + dp[i - 1][j - 1];
          else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

        }
      }
    }

    return dp[sz1][sz2];
  }
};