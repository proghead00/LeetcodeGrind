class Solution {
public:

  // states changing:
  // idx, k(2,1,0), buy(0,1)
  int dp[10001][3][2];

  int help(int idx, int n, int k, int buy, vector<int>& prices, vector<vector<vector<int>>> &dp) {

    if (idx == n or k == 0) return 0;

    // A transaction happens when I sell the stock that I have bought
    // Hence, k - 1 only when I sell it (one transcaction)

    if (dp[idx][k][buy] != -1) return dp[idx][k][buy];

    int profit = 0;

    if (buy == 1) {
      // buying
      int buying = -prices[idx] + help(idx + 1, n, k, 0, prices, dp);
      int skip = help(idx + 1, n, k, 1, prices, dp);
      profit = max(buying, skip);
    }

    else {
      // selling
      int sell =  prices[idx] + help(idx + 1, n, k - 1, 1, prices, dp);
      int skip = help(idx + 1, n, k, 0, prices, dp);
      profit = max(sell, skip);
    }

    return dp[idx][k][buy] = profit;
  }

  int maxProfit(vector<int>& prices) {
    vector<vector<vector<int>>> dp(prices.size(),
                                   vector<vector<int>>
                                   (3, vector<int>(2, -1)));

    return help(0, prices.size(), 2, 1, prices, dp);
  }
};