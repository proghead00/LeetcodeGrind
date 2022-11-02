class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0;
        
        int l = 0, r = 0;
        int ans = 0;
        
        while(r < nums.size() - 1) {
            farthest = 0;
            
            for(int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);    
            }
            
            l = r + 1;
            r = farthest;
            ans++;
        }
        
        return ans;
    }
};