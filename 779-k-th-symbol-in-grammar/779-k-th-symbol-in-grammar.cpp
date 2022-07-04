class Solution {
public:

  int flip(int x) {
    return x == 0 ? 1 : 0;
  }

  int kthGrammar(int n, int k) {
    if (n == 1) return 0;

    if (k & 1) return kthGrammar(n - 1, (k + 1) / 2);

    return flip(kthGrammar(n - 1, k / 2));
  }
};