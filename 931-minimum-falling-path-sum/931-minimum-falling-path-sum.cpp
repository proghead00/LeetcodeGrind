class Solution {
public:
    int help(vector<vector<int>> &matrix, int i, int j, vector<vector<int>>&dp) {

        if (j < 0) return 1e9;
        if (j >= matrix[0].size()) return 1e9;
        if (i == 0) return dp[i][j] = matrix[i][j];

        if (dp[i][j] != 1e9) return dp[i][j];

        int up, ld, rd;
        up = help(matrix, i - 1, j, dp);
        ld = help(matrix, i - 1, j - 1, dp);
        rd = help(matrix, i - 1, j + 1, dp);
        return dp[i][j] = matrix[i][j] + min({up, ld, rd});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int row = matrix.size();

        vector<vector<int>> dp(row, vector<int> (row, 1e9));
        int ans = INT_MAX;
        for (int k = 0; k < matrix[0].size(); k++)
            ans = min(ans, help(matrix, row - 1, k, dp))  ;

        return ans;
    }
};