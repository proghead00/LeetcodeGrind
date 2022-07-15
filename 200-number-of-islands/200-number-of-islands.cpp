class Solution {
public:
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  bool valid(int i, int j, int n, int m, vector<vector<char>> &grid) {
    if (i >= 0 and i < n and j >= 0 and j < m and grid[i][j] == '1')
      return true;
    return false;
  }

  void dfs(int i, int j, vector<vector<char>> &grid) {
    // i,j has 1 in the cell right now

    grid[i][j] = '0'; // make it as 0 once we go past it
                      // [since we don't wanna visit it again, else it'd be a never - ending recursion]

    for (int k = 0; k < 4; k++) {
      // new coordinates:
      int xx = i + dx[k];
      int yy = j + dy[k];

      if (valid(xx, yy, grid.size(), grid[0].size(), grid)) {

        // now run dfs from new coordinates (xx, yy) since it's valid
        dfs(xx, yy, grid);
      }
    }
    return;
  }

  int numIslands(vector<vector<char>> &grid) {
    int ans = 0;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          dfs(i, j, grid);
          // after the present DFS call is over, and when one connected
          // component is found, increment ans
          ans++;
        }
      }
    }

    return ans;
  }
};
