class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        unordered_map<char, int> mp;

        int ans = 0;

        while (r < s.size()) {
            if (mp.count(s[r]) and mp[s[r]] >= l and mp[s[r]] <= r) l = mp[s[r]] + 1;
            
            mp[s[r]] = r;
            ans = max(ans, r - l + 1);
            
            cout << l << " " << r << " " << endl;
            cout << ans << " " << endl;
            r++;
        }
        
        return ans;
    }
};