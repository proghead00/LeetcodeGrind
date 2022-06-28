class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp(row, vector<int>(col, 0));

        for (int j = 0; j < col; j++)
            dp[0][j] = matrix[0][j];


        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int ld = 1e9, rd = 1e9;
                int down = matrix[i][j] + dp[i - 1][j];

                if (j - 1 >= 0) ld = matrix[i][j] + dp[i - 1][j - 1];
                if (j + 1 < col) rd = matrix[i][j] + dp[i - 1][j + 1];

                dp[i][j] = min({down, ld, rd});

            }
        }

        int mn = 1e9;
        for (int k = 0; k < col; k++) mn = min(mn, dp[row - 1][k]);

        return mn;
    }
};