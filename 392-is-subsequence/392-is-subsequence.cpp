class Solution {
public:

    // s is a subsequence of t
    bool help(string s, string t, int n, int m) {
        if (!n) return true;
        if (!m) return false;

        if (s[n - 1] == t[m - 1])
            return help(s, t, n - 1, m - 1);

        else return help(s, t, n, m - 1);
    }
    bool isSubsequence(string s, string t) {
        return help(s, t, s.size(), t.size());
    }
};
