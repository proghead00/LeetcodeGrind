class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    // states changing:
    // i, cnt, buy(0,1)

    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1,
                                   vector<vector<int>>(k + 1,
                                       vector<int>(2, 0)));

    int profit = 0;
    int buy = 1; int cnt = k;

    for (int i = n; i >= 0 ; i--) {
      for (int cnt = 0; cnt <= k; cnt++) {
        for (int buy = 0; buy < 2; buy++) {
          if (i == n or cnt == 0) dp[i][cnt][buy] = 0;
          else {
            if (buy == 1) {
              // buying
              int buying = -prices[i] + dp[i + 1][cnt][0];
              int skip = dp[i + 1][cnt][1];
              profit = max(buying, skip);
            }
            else {
              // selling
              int sell =  prices[i] + dp[i + 1][cnt - 1][1];
              int skip = dp[i + 1][cnt][0];
              profit = max(sell, skip);
            }
            dp[i][cnt][buy] = profit;
          }
        }
      }
    }

    // NB: we are coming from the end, hence 0th
    return dp[0][cnt][buy];
  }

};