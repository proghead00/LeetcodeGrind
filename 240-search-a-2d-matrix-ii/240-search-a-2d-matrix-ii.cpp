class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     
        if(!matrix[0].size() or !matrix.size()) return false;
        
        // search from TOP RIGHT
        
        int i = 0, j = matrix[0].size()-1;
        
        // i moves DOWN and j moves LEFT
        
        while(i<matrix.size() and j>=0){
            if(matrix[i][j] == target) return true;
            
            else{
                if(matrix[i][j] > target) j--;
                else i++;
            }
        }
        
        return false;
    }
};