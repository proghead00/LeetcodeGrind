class Solution {
public:
    string minWindow(string s, string t) {


        if (s.size() == 0 or t.size() == 0 or s.size() < t.size())
            return "";

        int l = 0, r = 0;
        int cnt = 0;
        int len = INT_MAX, startIdx = 0;

        vector<int> v(256, 0);
        for (char x : t) v[x]++;

        while (r < s.size()) {

            if (v[s[r]] > 0) cnt++; // added the char to the current window

            v[s[r]]--;

            while (cnt == t.size()) {

                if (r - l + 1 < len) {
                    len = r - l + 1;
                    startIdx = l;
                }

                v[s[l]]++; // adding back the char since we are moving past it

                // after restoring the char, if the value is greater than 0, it means that it was a part of our probable answer window
                // so we redcuce cnt since we lost one char that might have been a part of our ans
                if (v[s[l]] > 0) cnt--;

                l++;
            }

            r++;
        }

        if (len == INT_MAX) return "";

        return s.substr(startIdx, len);

    }
};