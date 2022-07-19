class Solution {
public:
    //m, n, idx
    int dp[105][105][605];

    int help(vector<string>& strs, int m, int n, int idx) {

        if (idx == strs.size()) return 0;

        if (dp[m][n][idx] != -1) return dp[m][n][idx];

        int numZ = count(strs[idx].begin(), strs[idx].end(), '0');
        int numO = count(strs[idx].begin(), strs[idx].end(), '1');

        int skip, pick = -1e9;

        skip = help(strs, m, n, idx + 1);

        if (m - numZ >= 0 and  n - numO >= 0)
            pick = 1 + help(strs, m - numZ, n - numO, idx + 1);

        return dp[m][n][idx] = max(skip, pick);

    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return help(strs, m, n, 0);
    }
};