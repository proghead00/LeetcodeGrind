class Solution {
public:


  int help(int n, vector<int> &dp) {

    if (n <= 1) return 1;

    if (dp[n] != -1) return dp[n];

    int cur = 0;
    int mx = 0;

    // choices: 1 to n-1

    for (int i = 1; i <= n - 1; i++) {

      // numbers (choices): i, n-i ==> n-i can be further divided into subproblems and we need to pick the max
      // so recurrence is: i * max(n-i, f(n-i))

      cur = i * max(n - i, help(n - i, dp));
      mx = max(cur, mx);
    }

    return dp[n] = mx;

  }

  int integerBreak(int n) {

    vector<int> dp(n + 1, -1);
    return help(n, dp);

  }
};
