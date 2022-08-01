class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int l = 0, r = 0;
        unordered_map<char, int> mp;

        int ans = 0;

        while (r < s.size()) {

            if (mp.count(s[r])) l = max(l, mp[s[r]] + 1);

            mp[s[r]] = r;

            ans = max(ans, r - l + 1);

            r++;

        }

        return ans;
    }
};