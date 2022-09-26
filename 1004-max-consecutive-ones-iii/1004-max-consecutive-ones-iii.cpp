class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int r = 0, l = 0;
        int zz = 0;
        
        while(r < nums.size()) {
            
            if(nums[r] == 0) zz++;
            
            while(zz > k) {
                if(nums[l] == 0) zz--; // NB: nums[l]
                l++;
            }
            
            ans = max(ans, r - l + 1);
            r++;
        }
        
        return ans;
    }
};