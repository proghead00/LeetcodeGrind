class Solution {
public:
    void help(vector<int> nums, vector<vector<int>> &ans, int idx){
            if(idx == nums.size()){
                ans.push_back(nums);
                return;
            }
        
            for(int i = idx; i<nums.size(); i++){
                swap(nums[i], nums[idx]);
                help(nums, ans, idx + 1);
                
                // No need to swap back since I am passing nums as value, and not by reference
            }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        help(nums, ans, 0);
        
        return ans;
    }
};