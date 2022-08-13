class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int m = s.size(), n = words.size(), l = words[0].size();
    vector<int> ans;
    unordered_map<string, int> mp1;
    for (int i = 0; i < words.size(); i++) {
      mp1[words[i]]++;
    }
    for (int i = 0; i < m - (n * l) + 1; i++) {
      unordered_map<string, int> mp2 = mp1;
      for (int j = i; j < i + (n * l); j += l) {
        string temp = s.substr(j, l);
        //cout << temp << endl;
        if (mp2.find(temp) != mp2.end()) {
          if (mp2[temp] == 1) mp2.erase(temp);
          else mp2[temp]--;
        }
        else {
          break;
        }
      }
      if (mp2.empty()) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};