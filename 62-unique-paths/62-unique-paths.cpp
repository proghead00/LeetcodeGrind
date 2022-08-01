class Solution {
public:
    int dp[101][101];
    
    // 0,0, to m-1, n-1
    int help(int m, int n, int i, int j){
        if(j >= n or i >= m) return 0;
        
        if(i == m-1 and j == n-1) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = help(m, n, i+1, j) + help(m, n, i, j+1);
    }
    
    
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return help(m, n, 0, 0);
    }
};