class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        // unordered_map<int, int> mp1;
        vector<int> mp1(26);
        for (auto x : p) mp1[x - 'a']++;

        vector<int> ans;
        int l = 0;

        // unordered_map<int, int> mp2;
        vector<int> mp2(26);

        while (l < s.size()) {

            mp2[s[l] - 'a']++;

            if (l >= p.size()) mp2[s[l - p.size()] - 'a']--;

            if (mp1 == mp2) ans.push_back(l - p.size() + 1);

            l++;
        }

        return ans;
    }
};