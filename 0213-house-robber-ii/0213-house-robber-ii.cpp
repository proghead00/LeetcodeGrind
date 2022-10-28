class Solution {
public:
    int help(vector<int> &nums, int idx, int end, vector<int> &dp) {
        
        if(idx >= end) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        
        int pick = nums[idx] + help(nums, idx + 2, end, dp);
        int ignore = help(nums, idx + 1, end, dp);
            
        return dp[idx] = max(pick, ignore);
    }
    
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1) return nums[0];
        
        vector<int> dp1(nums.size() + 1, -1);
        vector<int> dp2(nums.size() + 1, -1);
        
        int temp1 = help(nums, 0, nums.size() - 1, dp1);
        int temp2 = help(nums, 1, nums.size(), dp2);
        
        return max(temp1, temp2);
    }
};