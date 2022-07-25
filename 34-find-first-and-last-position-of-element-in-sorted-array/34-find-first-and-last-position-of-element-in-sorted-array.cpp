class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if(binary_search(nums.begin(), nums.end(), target)){
            
            int ff = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            
            int ss = (upper_bound(nums.begin(), nums.end(), target) - nums.begin()) - 1;
            
            return {ff, ss};
        }
        
        else return {-1, -1};
    }
};