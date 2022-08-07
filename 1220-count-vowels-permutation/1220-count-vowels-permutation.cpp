class Solution {
public:
  int mod = 1e9 + 7;
  int dp[100005][115];

  long long int help(int n, int idx, char c) {
    if (idx == n)
      return 1;

    if (dp[idx][c - 'a'] != -1)
      return dp[idx][c - 'a'] % mod;

    long long int ans = 0;

    switch (c) {

    case 'a':
      ans += help(n, idx + 1, 'e') % mod;
      break;
    case 'e':
      ans += help(n, idx + 1, 'a') + help(n, idx + 1, 'i');
      break;
    case 'i':
      ans += help(n, idx + 1, 'a') + help(n, idx + 1, 'e') +
             help(n, idx + 1, 'o') + help(n, idx + 1, 'u');
      break;

    case 'o':
      ans += help(n, idx + 1, 'i') + help(n, idx + 1, 'u');
      break;

    case 'u':
      ans += help(n, idx + 1, 'a');
      break;
    }
    return dp[idx][c - 'a'] = ans % mod;
  }

  int countVowelPermutation(int n) {
    long long int ans = 0;
      
    vector<char> vowels{'a', 'e', 'i', 'o', 'u'};
    memset(dp, -1, sizeof(dp));

    for (char &c : vowels)
      ans += help(n, 1, c);

    return ans % mod;
  }
};
