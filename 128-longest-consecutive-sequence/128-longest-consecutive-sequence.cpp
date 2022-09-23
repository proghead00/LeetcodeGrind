class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x: nums) mp[x]++;
        
        int len = 0;
        int ans = 0;
        
        for(int x: nums){
            len = 1;
            if(mp.count(x-1)) continue;
            
            if(mp.count(x+1)){
                while(mp.count(x+1)){
                    len++;
                    x++;
                }
            }
            
            ans = max(ans, len);
        }
        
        return ans;
    }
};