class Solution {
public:
  bool isMatch(string s, string p) {

    int patSize = p.size();
    int ogSize = s.size();

    vector<vector<bool>> dp(patSize + 1, vector<bool>(ogSize + 1, false));

    // i --> idx_p (patSize)
    // j --> idx_s (ogSize)

    // we can fix * in p and check for other characters in s, hence
    // outer-looping wrt p

    //------------------------------------------------------
    // 1)  base case:

    // i==0, j==0 --> true
    dp[0][0] = true;

    // i==0 and j>0 --> false [j is non-zero so start from 1]
    for (int j = 1; j <= ogSize; j++) {
      // put i=0 in dp[i][j]
      dp[0][j] = false;
    }

    // i>0 and j==0 [i is non-zero so start from 1]
    for (int i = 1; i <= patSize; i++) {
      bool f = true;
      for (int k = 1; k <= i; k++) {
        if (p[k - 1] != '*') {
          f = false;
          break;
        }
      }
      // put j=0 in dp[i][j]
      dp[i][0] = f;
    }
    //------------------------------------------------------

    // 2)  recursive case:

    for (int i = 1; i <= patSize; i++) {
      for (int j = 1; j <= ogSize; j++) {

        if (s[j - 1] == p[i - 1] or p[i - 1] == '?')
          dp[i][j] = dp[i - 1][j - 1];

        else {
          if (p[i - 1] == '*')
            dp[i][j] = dp[i - 1][j] or dp[i][j - 1];
          else
            dp[i][j] = false;
        }
      }
    }

    return dp[patSize][ogSize];
  }
};
