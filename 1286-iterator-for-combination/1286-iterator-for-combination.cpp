class CombinationIterator {
public:
  int globalIdx = 0;
  vector<string> ans;

  void help(string &s, int n, int idx, string &temp) {
    if (temp.size() == n) {
      ans.push_back(temp);
      return;
    }

    for (int i = idx; i < s.size(); i++) {
      temp.push_back(s[i]);
      help(s, n, i + 1, temp);
      temp.pop_back();
    }
  }

  CombinationIterator(string characters, int combinationLength) {
    string temp = "";
    help(characters, combinationLength, 0, temp);
  }

  string next() {
    // return ans[globalIdx++];
    if (globalIdx <= ans.size()) return ans[globalIdx++];
    else return "";
  }

  bool hasNext() {
    return globalIdx < ans.size();
  }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */