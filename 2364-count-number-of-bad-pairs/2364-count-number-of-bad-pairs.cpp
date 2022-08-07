class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        /*
        j - i != nums[j] - nums[i]
        j - nums[j] != i - nums[i]
         
        [..., 4] -> Now, I got != as the condition, so I need to find if there are
                    j - 4  before this
        */
        
        unordered_map<int, int> mp;
   
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += i - mp[i - nums[i]];
            mp[i - nums[i]]++;
        }
        
        return ans;
    }
};