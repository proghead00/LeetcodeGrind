class Solution {
public:
  string help(const string &s, int &i) {
    string ans;

    while (i < s.length() and s[i] != ']') {
      if (!isdigit(s[i])) {
        ans += s[i];
        i++;
      } else {
        string n1;

        int num = 0;
        while (i < s.length() and isdigit(s[i])) {
          num = num * 10 + s[i] - '0';
          i++;
        }

        // int num = stoi(n1);

        // i points to '[' now, so move ahead by one
        i++;
        string temp = help(s, i);

        // i points to ']' now, so move ahead by one
        i++; // ']'

        while (num--)
          ans += temp;
      }
    }

    return ans;
  }

  string decodeString(string s) {
    int i = 0;
    return help(s, i);
  }
};
