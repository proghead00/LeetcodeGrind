class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0) return 0;
        
        unordered_map<int, int> mp;
        for(int x: nums) mp[x]++;
        
        int mx = 1, c = 1;
        
        for(int x: nums){
            
            if(mp.count(x-1)) continue;
            
            while(mp.count(x+1)) x++, c++, mp.erase(x);
            
            mx = max(c, mx);
            c = 1;
        } 
        
        return mx;
    }
};