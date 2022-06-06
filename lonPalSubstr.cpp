class Solution {
public:
  string longestPalindrome(string str) {

    int s = 0, e = 0;

    if (str.size() <= 1)
      return str;

    int ans = 1;

    // odd
    for (int i = 0; i < str.size(); i++) {
      int l = i, r = i;
      while (l >= 0 and r < str.size() and str[l] == str[r]) {
        l--;
        r++;
      }
      if (r - l - 1 > ans) {
        ans = r - l - 1;
        s = l + 1;
        e = r - 1;
      }
    }

    // even
    for (int i = 0; i < str.size(); i++) {
      int l = i, r = i + 1;
      while (l >= 0 and r < str.size() and str[l] == str[r]) {
        l--;
        r++;
      }
      if (r - l - 1 > ans) {
        ans = r - l - 1;
        s = l + 1;
        e = r - 1;
      }
    }
    return str.substr(s, ans);
  }
};
