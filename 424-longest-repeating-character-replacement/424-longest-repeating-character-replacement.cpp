class Solution {
public:
    int characterReplacement(string s, int k) {
        // we move the window and check for windowLength - maxFreq <= k everytime
        // windowLength - maxFreq is the no. of characters we need to replace

        unordered_map<char, int> mp;

        int l = 0, r = 0;
        int mxFreq = 0;
        int windowLength = 0;
        int ans = windowLength;

        while (r < s.size()) {

            mp[s[r]]++;

            windowLength = r - l + 1; // window will continue until replacements cross k

            // at every step I increase r, so rightwise it increases
            // I will increase l when I find windowLength - mxFreq crosses k

            mxFreq = max(mxFreq, mp[s[r]]);

            if (windowLength - mxFreq <= k) {
                // no need to move l
                ans = max(ans, windowLength);
            }
            else {
                // need to move l when it crosses k
                mp[s[l]]--; // since I am shifting l, I need to omit the presence of the current character at l
                l++;

            }
            // r will always move
            r++;
        }

        return ans;
    }
};