class Solution {
public:
  int help(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp) {

    if (!i and !j)
      return grid[0][0];

    if (i < 0 or j < 0)
      return 1e9;

    // NOTE: BE AWARE OF PLACING ARRAYS AT THE FRONT
    // WHEN i IS OUTTA BOUNDS, IT'LL THROW AN ERROR
    // HENCE, PUT DP CHECK AFTER THE ABOVE CONDITIONS
    if (dp[i][j] != 1e9)
      return dp[i][j];

    int up = grid[i][j] + help(grid, i - 1, j, dp);
    int left = grid[i][j] + help(grid, i, j - 1, dp);
    return dp[i][j] = min(up, left);
  }

  int minPathSum(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 1e9));
    return help(grid, n - 1, m - 1, dp);
  }
};
