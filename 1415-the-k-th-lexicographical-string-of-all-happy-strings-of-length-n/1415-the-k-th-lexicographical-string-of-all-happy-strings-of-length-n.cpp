class Solution {
public:
       vector<string> ans;

       void help(string& temp, string& s, int n, int k) {
              if (ans.size() == k) return;

              if (temp.size() == n) {
                     ans.push_back(temp);
                     return;
              }

              for (int i = 0; i < 3; i++) {
                     if (!temp.size() or temp.back() != s[i]) {
                            temp.push_back(s[i]);
                            help(temp, s, n, k);
                            temp.pop_back();
                     }
              }
       }


       string getHappyString(int n, int k) {
              string temp = "";
              string s = "abc";
              help(temp, s, n, k);

              return ans.size() == k ? ans.back() : "";
       }

};