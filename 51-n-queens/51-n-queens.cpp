class Solution {
public:
  //   fill(0, ans, temp, row, d1, d2, n);
  void fill(int c, vector<vector<string>> &ans, vector<string> &temp,
            bitset<9> &row, bitset<17> &d1, bitset<17> &d2, int n) {
    if (c == n) {
      ans.push_back(temp);
      return;
    }

    for (int r = 0; r < n; r++) {
      if (row[r] or d1[r + c] or d2[c - r + n - 1])
        continue;

      temp[r][c] = 'Q';
      row[r] = 1;
      d1[c + r] = 1;
      d2[c - r + n - 1] = 1;

      fill(c + 1, ans, temp, row, d1, d2, n);

      temp[r][c] = '.';
      row[r] = 0;
      d1[c + r] = 0;
      d2[c - r + n - 1] = 0;
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> temp(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
      temp[i] = s;

    bitset<9> row; // max row = n<=9
    bitset<17> d1; // 2*n-1 => max
    bitset<17> d2;

    fill(0, ans, temp, row, d1, d2, n);
    return ans;
  }
};
