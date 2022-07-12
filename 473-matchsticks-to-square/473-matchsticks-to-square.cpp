class Solution {
public:

       bool help(vector<int> &matchsticks, int eachSideMax, vector<int> &squareSides, int idx) {

              if (idx == matchsticks.size()) {
                     for (int k = 0; k < 3; k++) {
                            if (squareSides[k] != squareSides[k + 1]) return false;
                     }
                     return true;
              }

              // try out the choices: 4 sides
              for (int i = 0; i < 4; i++) {
                     if (squareSides[i] + matchsticks[idx] > eachSideMax) continue;

                     int j = i - 1;
                     // have I already calculated it?

                     while (j >= 0) {
                            if (squareSides[j] == squareSides[i]) break;
                            j--;
                     }

                     squareSides[i] += matchsticks[idx];
                     if (help(matchsticks, eachSideMax, squareSides, idx + 1))
                            return true;

                     // backtrack
                     squareSides[i] -= matchsticks[idx];
              }

              return false;
       }


       bool makesquare(vector<int>& matchsticks) {

              int peri = 0;
              for (int k = 0; k < matchsticks.size(); k++) peri += matchsticks[k];

              if (peri % 4 != 0 or !matchsticks.size()) return false;
              sort(matchsticks.begin(), matchsticks.end(), greater<int>());

              vector<int> squareSides(4, 0);

              int eachSideMax = peri / 4;
              return help(matchsticks, eachSideMax, squareSides, 0);

       }
};