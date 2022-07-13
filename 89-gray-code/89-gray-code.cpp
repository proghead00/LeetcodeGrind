class Solution {
public:
       int convert(int n) {
              int dec = 0, i = 0, rem;
              while (n != 0) {
                     rem = n % 10;
                     n /= 10;
                     dec += rem * pow(2, i);
                     ++i;
              }

              return dec;
       }

       vector<string> help(int n) {

              if (n == 1) {
                     return {"0", "1"};
              }

              vector<string> temp = help(n - 1);

              vector<string> zeroesAdd;
              vector<string> onesAdd;

              for (auto pp : temp) {
                     zeroesAdd.push_back("0" + pp);
              }

              reverse(temp.begin(), temp.end());
              for (auto pp : temp) {
                     onesAdd.push_back("1" + pp);
              }

              vector<string> merged;

              for (auto ff : zeroesAdd)
                     merged.push_back(ff);

              for (auto ff : onesAdd)
                     merged.push_back(ff);

              return merged;
       }

       vector<int> grayCode(int n) {
              vector<int> ans;

              string cur;
              vector<string> ansStr = help(n);

              for (auto x : ansStr) {
                     int y = stoi(x, 0, 2);
                     ans.push_back(y);
              }

              return ans;
       }
};