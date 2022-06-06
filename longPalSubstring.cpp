class Solution {
public:
  string longestPalindrome(string str) {
    // Write your code here.
    string ans = "";

    if (str.size() <= 1)
      return str;

    if (str.size() > 1) {
      if (str == string(str.rbegin(), str.rend()))
        return str;

    } else {

      for (int i = 0; i < str.size(); i++) {
        string s = str.substr(i);
        int mid = i;
        int l, r;
        if (s.size() % 2 == 0)
          l = mid - 1, r = mid;
        else
          l = mid - 1, r = mid + 1;

        while (l >= 0 and r < str.size() and str[l] == str[r]) {
          l--;
          r++;
        }
        string pp = s.substr(l + 1, r - 1);
        string rev = string(pp.rbegin(), pp.rend());

        int pps = pp.size();
        if (pps > ans.size() and pp == rev)
          ans = pp;

        cout << ans << endl;
      }
    }
    return ans;
  }
};
