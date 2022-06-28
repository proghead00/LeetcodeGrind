class Solution {
public:
    int help(vector<vector<int>> &obstacleGrid, int i, int j, vector<vector<int>>&dp) {
        if (i < 0 or j < 0 or obstacleGrid[i][j]) return 0;
        if (!i and !j) return 1;


        if (dp[i][j] != -1) return dp[i][j];

        int left, up;

        up = help(obstacleGrid, i - 1, j, dp);
        left = help(obstacleGrid, i, j - 1, dp);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));


        return help(obstacleGrid, obstacleGrid.size() - 1, obstacleGrid[0].size() - 1, dp);
    }
};
