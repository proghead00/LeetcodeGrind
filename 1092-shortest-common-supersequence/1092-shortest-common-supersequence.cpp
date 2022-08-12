/*
Input: str1 = "abac", str2 = "cab"
Output: "cabac"

Let's analyze it:

What's the MAXIMUM insertions that I can make to merge str1 and str2?
The resultant string can be ababcab, which would give an answer of 7, which is obviously not optimal
Why?
Since we DO NOT need to insert the common sequences available.
LCS!

LCS is ab (2)
So we do not need to insert "ab".
What do we need to insert? The remaining characters of both the strings,
which is "ac" and "c" and the total length hence is 2 (size1) + 1(size2) = 3

Formulating them:
(Size of s1 - LCS) + (Size of s2 - LCS) + LCS

Therefore the final answer would be (4-2) + (3-2) + 2 = 2 + 1 + 2 = 5
*/

class Solution {
public:

  string shortestCommonSupersequence(string str1, string str2) {

    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        if (i == 0 or j == 0) dp[i][j] == 0;
        else {
          if (str1[i - 1] == str2[j - 1]) dp[i][j] =  1 + dp[i - 1][j - 1];
          else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
      }
    }

    // find lcs string
    string ans;

    int i = n, j = m;
      
    while (i and j) {
      if (str1[i - 1] == str2[j - 1]) {
        ans.push_back(str1[i - 1]);
        i--, j--;
      }

      else {
        if (dp[i - 1][j] >  dp[i][j - 1]) {
          // here, one row will be lifted up, and s1 is represented by the rows, so we'll get a character being reduced
          // hence, we take str1[i-1]

          ans.push_back(str1[i - 1]);
          i--;
        }

        else {
          ans.push_back(str2[j - 1]); //str2 because columns are represented by characters of s2
          j--;
        }

      }
    }

    while (i--) ans.push_back(str1[i]);
    while (j--) ans.push_back(str2[j]);

    reverse(ans.begin(), ans.end());
    return ans;

  }
};