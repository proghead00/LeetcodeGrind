class Solution {
public:

    int findSubstringInWraproundString(string p) {
        unordered_map<char, int> mp;

        int streak = 1;

        for (int i = 0; i < p.size(); i++) {

            // duplicate found
            // if (mp.count(p[i])) streak = 1;

            // contiguous
            if (i and (p[i] - p[i - 1] == 1)) streak++;

            // z...a case
            else if (i and (p[i] == 'a' and p[i - 1] == 'z')) streak++;

            else streak = 1;

            mp[p[i]] = max(mp[p[i]], streak);
        }


        int ans = 0;
        for (auto x : mp) {
            ans += x.second;
        }

        return ans;
    }
};