class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int ans = 0;
        
        int n = matrix.size();
        int l = matrix[0][0], h = matrix[n - 1][n - 1];
        
        while(l < h){
            ans = 0;
            int mid = l + (h - l) / 2;
            
            for(int i = 0; i < n; i++){
                ans += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            
            if(ans < k) l = mid + 1;
            else h = mid;
        }
        
        return l;
    }
};