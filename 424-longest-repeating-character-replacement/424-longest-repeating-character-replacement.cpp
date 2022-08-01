class Solution {
public:
    int characterReplacement(string s, int k) {
        // we move the window and check for windowLength - maxFreq <= k everytime

        unordered_map<char, int> mp;

        int l = 0, r = 0;
        int mx = 0;
        int windowLength = 0;
        int ans = windowLength;

        while (r < s.size()) {
            mp[s[r]]++;

            windowLength = r - l + 1;
            // at every step I increase r, so rightwise it increases
            // I will increase l when I find it crosses k

            mx = max(mx, mp[s[r]]);

            if (windowLength - mx <= k) {
                // no need to move l
                ans = max(ans, windowLength);
            }
            else {
                // need to move l when it crosses k
                mp[s[l]]--;
                l++;

            }
            // r will always move
            r++;
        }

        return ans;
    }
};