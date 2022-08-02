class Solution {
public:
  int ans = 0;

  void help(int n, bitset<9> &rows, bitset<18> &ld,
            bitset<18> &rd, int c) {
    if (c == n) {
      ans++;
      return;
    }

    for (int r = 0; r < n; r++) {
      if (rows[r] == 0 and ld[r + c] == 0 and rd[c - r + n - 1] == 0) {
        rows[r] = 1;
        ld[r + c] = 1;
        rd[c - r + n - 1] = 1;
        help(n, rows, ld, rd, c + 1);

        rows[r] = 0;
        ld[r + c] = 0;
        rd[c - r + n - 1] = 0;
      }
    }
  }
  int totalNQueens(int n) {
    bitset<9> rows(0);
    bitset<18> ld(0);
    bitset<18> rd(0);
    help(n, rows, ld, rd, 0);
    return ans;
  }
};
