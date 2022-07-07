class Solution {
public:
       // rows change simultaneously, so we can keep a single variable for it
       // columns change for both

       int dp[71][71][71];
       int help(vector<vector<int>> &grid, int i, int j1, int j2) {

              if (j1 < 0 or j1 >= grid[0].size() or j2 < 0 or j2 >= grid[0].size()) return -1e9;

              if (i == grid.size() - 1) {
                     if (j1 == j2) return  dp[i][j1][j2] = grid[i][j1];
                     else return  dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
              }

              // for every choice of robot1, I have 3 choices of robot2
              // hence, 3 * 3 = 9

              if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

              int mx = 0;

              // -1, 0, 1 (three directions)
              for (int outer = -1; outer <= 1; outer++) {
                     for (int inner = -1; inner <= 1; inner++) {

                            int val = 0;

                            if (j1 == j2) val = grid[i][j1]; // or grid[i][j2]
                            else val = grid[i][j1] + grid[i][j2];

                            // explore the rest of the grid
                            val += help(grid, i + 1, j1 + outer, j2 + inner);

                            mx = max(mx, val);
                     }
              }

              return dp[i][j1][j2] = mx;
       }

       int cherryPickup(vector<vector<int>>& grid) {
              memset(dp, -1, sizeof(dp));
              return help(grid, 0, 0, grid[0].size() - 1);
       }
};