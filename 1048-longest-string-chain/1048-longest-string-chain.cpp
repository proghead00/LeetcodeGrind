class Solution {
public:

    static bool cmp(string a, string b) {
        return a.size() < b.size();
    }

    bool diff(string &s1, string &s2) {
        // s1 is longer
        if (s1.size() != s2.size() + 1) return false;

        int ff = 0, ss = 0;

        while (ff < s1.size()) {
            if (s1[ff] == s2[ss]) ff++, ss++;
            else ff++;

        }

        if (ss + 1 == ff) return true;
        else return false;
    }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(), cmp);

        vector<int> dp(words.size(), 1);

        for (int i = 1; i < words.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] + 1 > dp[i] and diff(words[i], words[j]))
                    dp[i] = dp[j] + 1;
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};