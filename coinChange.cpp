
long help(int *denominations, int n, int value) {
  // Write your code here

  if (!value)
    return 1;
  if (!n)
    return (value % denominations[0] == 0);

  // moving from the last element

  // not taking the coin
  int ans = help(denominations, n - 1, value);

  // taking the coin
  if (denominations[n - 1] <= value)
    ans = ans + help(denominations, n, value - denominations[n - 1]);
  if (denominations[n - 1] <= value)
    ans = ans + help(denominations, n - 1, value - denominations[n - 1]);

  return ans;
}

long countWaysToMakeChange(int *denominations, int n, int value) {
  // Write your code here
  //   vector<int> dp(value + 1, 0);
  return help(denominations, n, value);
}
