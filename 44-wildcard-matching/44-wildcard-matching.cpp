class Solution {
public:

  // int dp[2001][2001];

  bool help(string &s, string &p, int idx_s, int idx_p, vector<vector<int>> &dp) {

    // base conditions:
    if (idx_p < 0 and idx_s < 0) return true;

    if (idx_s >= 0 and idx_p < 0) return false; // string's left, but there's no pattern left

    if (idx_s < 0 and idx_p >= 0) {
      for (int i = 0; i <= idx_p; i++) if (p[i] != '*') return false; // since only * can match with empty sequence

      //NB: I missed out to return true previusly, hence -ve index threw obvious errors:
      return true;
    }


    if (dp[idx_s][idx_p] != -1) return dp[idx_s][idx_p];


    // recurrence:

    // chars match
    if (s[idx_s] == p[idx_p] or p[idx_p] == '?') return dp[idx_s][idx_p] = help(s, p, idx_s - 1, idx_p - 1, dp);


    // * is encountered
    if (p[idx_p] == '*') {

      // option 1: use * as nothing
      bool op1 = help(s, p, idx_s, idx_p - 1, dp);

      // option 2: use * as a matching ==> fix * and move the other string
      bool op2 = help(s, p, idx_s - 1, idx_p, dp);

      return dp[idx_s][idx_p] = op1 or op2;
    }

    else return dp[idx_s][idx_p] = false;

  }


  bool isMatch(string s, string p) {

    // p will be the pattern, having ?, *...

    // memset(dp, -1, sizeof(dp));

    vector<vector<int>> dp(s.size(), vector<int> (p.size(), -1));

    return help(s, p, s.size() - 1, p.size() - 1, dp);

  }
};