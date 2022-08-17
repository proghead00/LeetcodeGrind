class Solution {
public:
  int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> v = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    
    set<string> setCode;

    for (auto word : words) {
      string ss = "";
      for (auto ch : word) ss += v[ch - 'a'];
      setCode.insert(ss);
    }

    return setCode.size();
  }
};