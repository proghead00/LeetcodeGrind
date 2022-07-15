class Solution {
public:
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  bool valid(int i, int j, int n, int m, vector<vector<int>> &grid) {
    if (i >= 0 and i < n and j >= 0 and j < m and grid[i][j])
      return true;
    return false;
  }

  int dfs(int i, int j, vector<vector<int>> &grid) {
    // i,j has 1 in the cell right now
    
    int ans = 1; // current cell has area of 1

    grid[i][j] = 0; // make it as 0 once we go past it
                    // [since we don't wanna visit it again, else it'd be a never-ending recursion]

    for (int k = 0; k < 4; k++) {
      // new coordinates:
      int xx = i + dx[k];
      int yy = j + dy[k];

      if (valid(xx, yy, grid.size(), grid[0].size(), grid)) {

        // now run dfs from new coordinates (xx, yy) since it's valid
        ans += dfs(xx, yy, grid);
      }
    }

    return ans;
  }

  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int mx = 0;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j]) {
          int cnt = dfs(i, j, grid); // area of one connected component
          mx = max(mx, cnt);
        }
      }
    }

    return mx;
  }
};
