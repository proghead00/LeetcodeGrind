class Solution {
public:

    int mod = 1e9 + 7;

    int dx[4] = { -1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int help(int r, int c, int i, int j, int maxMove, vector<vector<vector<int>>> &dp) {
        // currently I am at (i, j)

        if (i < 0 or i >= r or j < 0 or j >= c) return 1;
        if (maxMove == 0) return 0;

        if (dp[i][j][maxMove] != -1) return dp[i][j][maxMove];
        int ans = 0;
        for (int k = 0; k < 4; k++) {
            int xx = i + dx[k];
            int yy = j + dy[k];

            ans += help(r, c, xx, yy, maxMove - 1, dp);
            ans %= mod;
        }
        return dp[i][j][maxMove] = (ans %= mod);
    }

    int findPaths(int r, int c, int maxMove, int startRow, int startColumn) {

        vector<vector<vector<int>>> dp(r + 1, vector<vector<int>>(c + 1, vector<int>(maxMove + 1, -1)));
        return help(r, c, startRow, startColumn, maxMove, dp);
    }
};