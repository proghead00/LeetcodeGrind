class Solution {
public:

    int dp[305][305];


    int changes[3][2] = {{0, 1}, {1, 0}, {1, 1}};

    bool valid(vector<vector<char>> &matrix, int xx, int yy) {
        if (xx >= 0 and yy >= 0 and xx < matrix.size() and yy < matrix[0].size()) return true;
        else return false;
    }

    int help(vector<vector<char>> &matrix, int i, int j) {

        if (!valid(matrix, i, j)) return 0;

        if (matrix[i][j] == '0') return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int ans = 1e9;

        for (int k = 0; k < 3; k++) {
            int cur = 1;

            int xx = i + changes[k][0];
            int yy = j + changes[k][1];

            // call for right, diag, and down and take the min

            // initial cell (cur) has a size of 1
            // current cell hence has cumulative answer
            cur += help(matrix, xx, yy);
            ans = min(ans, cur);
        }

        return dp[i][j] = ans;

    }


    int maximalSquare(vector<vector<char>>& matrix) {
        memset(dp, -1, sizeof(dp));

        int ans = -1e9;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    ans = max(ans, help(matrix, i, j));
                }
            }
        }

        return ans == -1e9 ? 0 : ans * ans;
    }
};