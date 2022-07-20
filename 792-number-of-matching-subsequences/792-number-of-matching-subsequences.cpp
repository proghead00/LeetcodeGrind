class Solution {
public:
    bool check(const string &og, const string w) {

        // O(max(og, w)) => O(og)

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

        // O(w)
        for (int i = 0; i < words.size(); i++) mp[words[i]]++;

        int ans = 0;

        for (auto pp : mp)
            // O(w * max(s, w)) => O(w * s)
            if (check(s, pp.first)) ans += pp.second; // for multiple occurences of words

        return ans;
    }
};