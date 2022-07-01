class Solution {
public:

  string reverseF(string s) {
    reverse(s.begin(), s.end());
    return s;
  }

  string invert(string s) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0') s[i] = '1';
      else s[i] = '0';
    }
    return s;
  }

  string help(int n, int k) {
    if (n == 1)
      return "0";

    string temp = help(n - 1, k);
    string ans = temp + "1" + reverseF(invert(temp));

    return ans;
  }
  char findKthBit(int n, int k) {
    string ans = help(n, k);
    return ans[k - 1];
  }
};
