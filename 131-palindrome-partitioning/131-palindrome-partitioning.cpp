class Solution {
public:
  bool isPal(string &s, int start, int end) {
    while (start < end) {
      if (s[start] != s[end])
        return false;
      start++;
      end--;
    }
    return true;
  }

  void help(string &s, int idx, vector<string> temp,
            vector<vector<string>> &ans) {
    if (idx == s.size()) {
      ans.push_back(temp);
      return;
    }

    for (int i = idx; i < s.size(); i++) {
      if (isPal(s, idx, i)) {
        temp.push_back(s.substr(idx, i - idx + 1));
        help(s, i + 1, temp, ans);
        temp.pop_back();
      }
      
    }
  }
    
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> temp;
    help(s, 0, temp, ans);
    return ans;
  }
};
