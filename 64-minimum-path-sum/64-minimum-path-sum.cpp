class Solution {
public:
  int help(vector<vector<int>> &grid, int n, int m, vector<vector<int>> &dp) {

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!i and !j)
          dp[i][j] = grid[i][j];
          
        else {
          int up = i ? dp[i - 1][j] : 1e9;
          up += grid[i][j];

          int left = j ? dp[i][j - 1] : 1e9;
          left += grid[i][j];
            
          dp[i][j] = min(up, left);
        }
      }
    }
    return dp[n - 1][m - 1];
  }

  int minPathSum(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));
    return help(grid, n, m, dp);
  }
};
