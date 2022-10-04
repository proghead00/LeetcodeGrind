class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<int> dp(nums.size(), 1), track(nums.size());
       
        int idx = 0, mx = 1;
        
        // update dp and track 
        
        for(int i = 1; i < nums.size(); i++){
            
            track[i] = i;
            
            for(int j = 0; j < i; j++){
                // nums[j] <= nums[i], so we gotta check whether nums[j] divides nums[i]
                
                if(nums[i] % nums[j] == 0) {
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1; // length increases by 1
                        track[i] = j;
                    }
                }
            }
            
            if(dp[i] > mx){
                mx = dp[i];
                idx = i;
            }
        }
         
        vector<int> temp;
        
        temp.push_back(nums[idx]);
        
        while(track[idx] != idx){
            idx = track[idx];
            temp.push_back(nums[idx]);
        }
        
        return temp;
    }
};