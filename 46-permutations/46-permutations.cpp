class Solution {
public:
    
    void help(vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, unordered_map<int, int> &mp){
        
        if(temp.size()==nums.size()) {
            ans.push_back(temp);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(mp[nums[i]] == 1) continue;
            
            mp[nums[i]] = 1;
            
            temp.push_back(nums[i]);
            
            help(nums, temp, ans, mp);
            
            // backtrack
            mp[nums[i]] = 0;
            temp.pop_back();
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        vector<int> temp;
        
        help(nums, temp, ans, mp);
        
        return ans;
    }
};