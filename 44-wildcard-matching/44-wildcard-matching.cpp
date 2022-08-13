class Solution {
public:

  bool isMatch(string s, string p) {

    int ogSize = s.size();
    int patSize = p.size();

    vector<vector<bool>> dp(patSize + 1, vector<bool> (ogSize + 1, false));


    // we can fix * in p and check for other characters in s, hence outer looping wrt p
    // i --> idx_p
    // j --> idx_s

    for (int i = 0; i <= patSize; i++) {
      for (int j = 0; j <= ogSize; j++) {

        if (j == 0 and i == 0) {
          dp[i][j] = true;
        }

        else if (i == 0 and j)  {
          dp[i][j] = false;
        }

        else if (j == 0 and i) {
          bool f = true;
          for (int kk = 1; kk <= i; kk++) {
            if (p[kk - 1] != '*') {
              f = false;
              break;
            }
          }
          dp[i][j] = f;
        }

        else {

          if (p[i - 1] == s[j - 1] or p[i - 1] == '?') dp[i][j] = dp[i - 1][j - 1];

          else if (p[i - 1] == '*') {
            dp[i][j] = dp[i - 1][j] or dp[i][j - 1];
          }
          else dp[i][j] = false;
        }
      }
    }

    return dp[patSize][ogSize];

  }
};