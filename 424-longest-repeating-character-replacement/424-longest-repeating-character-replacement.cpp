class Solution {
public:
    int characterReplacement(string s, int k) {
      
        unordered_map<char, int> mp;
        int mx = 0, windowLen;
        
        int l = 0, r = 0, ans = 0;
        
        while(r < s.size()){
            mp[s[r]]++;
            mx = max(mx, mp[s[r]]);
            windowLen = r - l + 1;
            
            if(windowLen - mx > k) {
                mp[s[l]]--;
                l++;
            }
            else{
                ans = max(ans, windowLen);
            }
            r++;
        }
        
        return ans;
        
    }
};