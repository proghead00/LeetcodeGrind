class Solution {
public:
       // traversing from the end of the strings

       // cases:
       // NOTE: FIRST CASE SHOULD BE TO PICK EITHER OF THE PATHS

       // 1 -> both s1's and s2's char matches s3's ==> help(s1,s2,s3, l1-1, l2-1, l3-1) ==> pick either of the paths (the best one)

       // 2 -> s1's char matches s3's ==> help(s1, s2, s3, l1-1, l2, l3-1)
       // 3 -> s2's char matches s3's ==> help(s1,s2,s3, l1, l2-1, l3-1)

       int dp[105][105][205];
       bool help(string &s1, string &s2, string &s3, int l1, int l2, int l3) {

              if (l3 < 0 and l1 < 0 and l2 < 0) return true;

              if (l1 >= 0 and l2 >= 0 and l3 >= 0 and dp[l1][l2][l3] != -1) return dp[l1][l2][l3];

              // case 1: pick either of the paths
              if (l1 >= 0 and l2 >= 0 and s1[l1] == s3[l3] and s2[l2] == s3[l3]) {
                     bool first, second;
                     first = help(s1, s2, s3, l1 - 1, l2, l3 - 1);
                     second = help(s1, s2, s3, l1, l2 - 1, l3 - 1);
                     return dp[l1][l2][l3] = first or second;
              }
              // case 2:
              else if (l1 >= 0 and s1[l1] == s3[l3])
                     return help(s1, s2, s3, l1 - 1, l2, l3 - 1);

              // case 3:
              else if (l2 >= 0 and s2[l2] == s3[l3])
                     return help(s1, s2, s3, l1, l2 - 1, l3 - 1);

              else return false;
       }

       bool isInterleave(string s1, string s2, string s3) {

              int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
              // vector<vector<vector<int>>> dp(l1 + 1, vector<vector<int>>(l2 + 1, vector<int>(l3 + 1, -1)));
              memset(dp, -1, sizeof(dp));

              if (l1 + l2 != l3) return false;
              return help(s1, s2, s3, l1 - 1, l2 - 1, l3 - 1);
       }
};
