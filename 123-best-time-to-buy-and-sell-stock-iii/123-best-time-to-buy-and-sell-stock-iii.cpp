class Solution {
public:
  int maxProfit(vector<int>& prices) {
    // states changing:
    // i, k(2,1,0), buy(0,1)

    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1,
                                   vector<vector<int>>
                                   (3, vector<int>(2, 0)));

    int profit = 0;
    int buy = 1, k = 2;

    for (int i = n - 1; i >= 0 ; i--) {
      for (int k = 0; k < 3; k++) {
        for (int buy = 0; buy < 2; buy++) {
          if (i == n or k == 0) dp[i][k][buy] = 0;
          else {
            if (buy == 1) {
              // buying
              int buying = -prices[i] + dp[i + 1][k][0];
              int skip = dp[i + 1][k][1];
              profit = max(buying, skip);
            }
            else {
              // selling
              int sell =  prices[i] + dp[i + 1][k - 1][1];
              int skip = dp[i + 1][k][0];
              profit = max(sell, skip);
            }
            dp[i][k][buy] = profit;
          }
        }
      }
    }
    return dp[0][k][buy];
  }

};