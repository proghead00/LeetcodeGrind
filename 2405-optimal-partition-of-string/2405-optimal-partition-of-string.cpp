class Solution {
public:
    int partitionString(string s) {
        // maximize the current partition as long as possible

        unordered_map<int, bool> mp;
        int l = 0, r = 0;
        int ans = 1;
        
        while(r < s.size()) {
            if(mp[s[r]]) {
                // new partition
                mp.clear();
                ans++;
            }    
            
            mp[s[r]] = true;
            r++;
        }
        
        return ans;
    }
};