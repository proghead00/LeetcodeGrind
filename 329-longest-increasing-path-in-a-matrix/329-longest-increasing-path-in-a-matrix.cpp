class Solution {
public:
    int changes[4][2] = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
    int dp[201][201];

    bool valid(int xx, int yy, int n, int m) {
        if (xx >= 0 and yy >= 0 and xx < n and yy < m) return true;
        else return false;
    }

    int help(vector<vector<int>> &matrix, int i, int j, int n, int m) {

        if (dp[i][j] != -1) return dp[i][j];

        int ans = 0;

        for (int k = 0; k < 4; k++) {

            // NB: NEED TO INITIALISE cur here else I'll get accumulated values from different calls of directions
            int cur = 1;

            int xx = i + changes[k][0];
            int yy = j + changes[k][1];

            if (valid(xx, yy, n, m)) {
                if (matrix[i][j] < matrix[xx][yy]) {

                    // current directions path length
                    cur += help(matrix, xx, yy, n, m);
                }
            }

            // max of the current cell for and updates itself for all the directions
            ans = max(ans, cur);
        }

        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        memset(dp, -1, sizeof(dp));

        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < m; j++) {
                // help will give the total length of path of THAT cell
                // and I want max by updating wrt all the cells
                ans = max(ans, help(matrix, i, j, n, m));
            }

        }

        return ans;
    }
};