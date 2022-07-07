class Solution {
public:
       // rows change simultaneously, so we can keep a single variable for it
       // columns change for both

       int dy[3] = {0, -1, 1};
       int dp[71][71][71];
       int help(vector<vector<int>> &grid, int i, int r1, int r2) {

              if (i == grid.size()) return 0;

              if (r1 < 0 or r1 >= grid[0].size() or r2 < 0 or r2 >= grid[0].size()) return -1e9;

              // for every choice of robot1, I have 3 choices of robot2
              // hence, 3 * 3 = 9

              if (dp[i][r1][r2] != -1) return dp[i][r1][r2];

              int mx = 0;

              for (int outer = 0; outer < 3; outer++) {
                     for (int inner = 0; inner < 3; inner++) {
                            mx = max(mx, help(grid, i + 1, r1 + dy[outer], r2 + dy[inner]));
                     }
              }

              if (r1 == r2) mx += grid[i][r1]; // or grid[i][r2]
              else mx += grid[i][r1] + grid[i][r2];

              return dp[i][r1][r2] = mx;
       }

       int cherryPickup(vector<vector<int>>& grid) {
              memset(dp, -1, sizeof(dp));
              return help(grid, 0, 0, grid[0].size() - 1);
       }
};