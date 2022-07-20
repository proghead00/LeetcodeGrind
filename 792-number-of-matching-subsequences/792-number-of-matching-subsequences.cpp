class Solution {
public:
    bool check(const string &og, const string w) {

        // at max, I need to move thru the og string trying to find for the character

        // 2 pointers approach
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

        for (int i = 0; i < words.size(); i++) mp[words[i]]++;

        int ans = 0;

        //  hashmap has all the unique words
        // O(s * (w * L)) => w = no. of unique words, L = max length of word

        for (auto pp : mp)
            if (check(s, pp.first)) ans += pp.second; // for multiple occurences of words

        return ans;
    }
};