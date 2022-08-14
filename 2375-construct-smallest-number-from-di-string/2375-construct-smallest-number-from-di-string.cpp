class Solution {
public:
  string smallestNumber(string pattern) {
    string init;
    int n = pattern.size();

    // fill init from 1 to 9
    for (char i = '1'; i <= '9'; i++) {
      init.push_back(i);
    }

    string temp = init.substr(0, n + 1);

    for (int i = 0; i < pattern.size(); i++) {
      int s = i; // track the index just before we get D
      while (pattern[i] == 'D') {
        i++;
      }
      if (s != i)
        reverse(temp.begin() + s, temp.begin() + i + 1);
    }

    string ans;
    for (char c : temp) {
      ans.push_back(c);
    }
    return ans;
  }
};
