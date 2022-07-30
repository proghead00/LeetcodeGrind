class Solution {
public:
  vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
    vector<string> result;
    vector<int> counts(26, 0);
    
    for (auto &word : words2) {
      vector<int> counts2(26, 0);
      for (auto &c : word)
        counts2[c - 'a']++;
      for (int i = 0; i < 26; i++)
        counts[i] = max(counts[i], counts2[i]);
    }
    for (auto &word : words1) {
      vector<int> counts2(26, 0);
      for (auto &c : word)
        counts2[c - 'a']++;
      bool ok = true;
      for (int i = 0; i < 26; i++)
        if (counts2[i] < counts[i])
          ok = false;
      if (ok)
        result.push_back(word);
    }
    return result;
  }
};
