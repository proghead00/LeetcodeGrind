class Solution {
public:
    bool check(string &og, string w) {
        int i = 0, j = 0;
        while (i < og.size() and j < w.size()) {
            if (og[i] == w[j]) i++, j++;
            else i++;
        }

        if (j == w.size()) return true;
        else return false;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<string, int> mp;

        for (int i = 0; i < words.size(); i++) {
            mp[words[i]]++;
        }

        int ans = 0 ;
        for (auto pp : mp)
            if (check(s, pp.first)) ans += pp.second;

        return ans;
    }
};