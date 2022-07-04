class Solution {
  int mod = 1e9 + 7;

public:
  long long pwr(long long a, long long b) {
    if (!b)
      return 1;

    long long ans = pwr(a, b / 2);
    ans = (ans % mod * ans % mod) % mod;
    if (b & 1)
      ans = (ans * a) % mod;

    return ans;
  }

  int countGoodNumbers(long long n) {
    long long odd = n / 2;
    long long even = n / 2 + n % 2;
    // even ==> 0 2 4 6 8: (5 numbers)
    // odd ==> 1 3 5 7: (4 numbers)
    return (int)((pwr(5, even) * pwr(4, odd)) % mod);
  }
};
