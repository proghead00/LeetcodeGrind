class Solution {
public:
    
    void help(vector<vector<string>> &ans, int c, int n, vector<int> &ld, vector<int> &ud, vector<int> &row, vector<string> &temp){
        
        if(c == n){
            ans.push_back(temp);
            return;
        }
        
        for(int r = 0; r < n; r++){
            if(ld[r + c] or row[r] or ud[c - r + n - 1]) continue;
            
            ld[r + c] = 1;
            row[r] = 1;
            ud[c - r + n - 1] = 1;
            temp[r][c] = 'Q';
            
            help(ans, c + 1, n, ld, ud, row, temp);
            
            ld[r + c] = 0;
            row[r] = 0;
            ud[c - r + n - 1] = 0;
            temp[r][c] = '.';
        }
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        
        vector<int> ld(2*n);
        vector<int> ud(2*n);
        vector<int> row(n);
        
        string s(n, '.');
        vector<string> temp(n);
        for(int i = 0; i < n; i++) temp[i] = s; // every row with '.'
        
        help(ans, 0, n, ld, ud, row, temp);
        
        return ans;
    }
};