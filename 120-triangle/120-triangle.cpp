// #define INT_MAX 1e6

class Solution {
public:
  int help(vector<vector<int>> &triangle, int i, int j,
           vector<vector<int>> &dp) {

    if (i == triangle.size())
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    int ans =
        min(help(triangle, i + 1, j, dp), help(triangle, i + 1, j + 1, dp));

    // return the sum of the below (ans) returned and the current (triangle[i][j])
    return dp[i][j] = triangle[i][j] + ans;
  }

  int minimumTotal(vector<vector<int>> &triangle) {
    vector<vector<int>> dp(triangle.size(),
                           vector<int>(triangle.size(), -1));
    return help(triangle, 0, 0, dp);
  }
};
