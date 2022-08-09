class Solution {
public:

  int longestCommonSubsequence(string s1, string s2) {
    int sz1 = s1.size();
    int sz2 = s2.size();

    vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1, 0));

    /*
     form the base case
      loop i, j in opposite fashion since we are changing a top-down to bottom-up
      copy the recurrence

      base case
      if (i == 0 or j == 0) return 0;
      NB: Here, OR signifies that if i==0 j can be anything in it's range and vice versa
    */


    // if i == 0 ==> put 0 in ith (row) and j can be anything
    // return 0, so the value should be 0

    // loop starts from 1, since 0th ones are filled
    for (int i = 1; i <= sz1; i++) {
      for (int j = 1; j <= sz2; j++) {

        // base case
        if (i == 0 or j == 0) dp[i][j] = 0;

        else {

          if (s1[i - 1] == s2[j - 1])  dp[i][j] = 1 + dp[i - 1][j - 1];
          else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

        }
      }
    }

    return dp[sz1][sz2];
  }
};