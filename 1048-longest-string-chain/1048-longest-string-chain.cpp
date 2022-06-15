class Solution {
public:
  static bool cmp(const string &s1, const string &s2) {
    return s1.size() < s2.size();
  }

  int longestStrChain(vector<string> &words) {
    sort(words.begin(), words.end(), cmp);
    unordered_map<string, int> dp;
    int ans = 0;
    for (auto pp : words) {
      for (int i = 0; i < pp.size(); i++) {
        string pre = pp.substr(0, i) + pp.substr(i + 1);
        dp[pp] = max(dp[pp], dp.find(pre) == dp.end() ? 1 : dp[pre] + 1);
      }
      ans = max(ans, dp[pp]);
    }
    return ans;
  }
};
