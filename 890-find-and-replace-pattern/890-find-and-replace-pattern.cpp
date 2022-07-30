class Solution {
public:
    bool help(string words, string pattern) {
        unordered_map<char, char> mp;
        for (int i = 0; i < words.size(); i++) {
            if (mp.count(words[i]) == 0) {
                mp[words[i]] = pattern[i];
            }
            else {
                if (mp[words[i]] != pattern[i]) return false;
            }
        }

        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;

        for (string w : words) {
            bool bothways = help(w, pattern) & help(pattern, w);
            if (bothways) ans.push_back(w);
        }

        return ans;
    }
};