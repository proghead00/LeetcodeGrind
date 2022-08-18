class Solution {
public:
// states changing: buy, idx, cnt
  int dp[2][1001][101];

  int help(int k, vector<int> &prices, int buy, int idx, int cnt) {
    if (idx == prices.size() or cnt == k) {
      return 0;
    }

    if (dp[buy][idx][cnt] != -1) return dp[buy][idx][cnt];

    int profit = 0;
    if (buy == 1) {
      // buy or skip => take max of them
      int take = -prices[idx] + help(k, prices, 0, idx + 1, cnt);
      int skip = help(k, prices, 1 , idx + 1, cnt);
      profit = max(take, skip);
    }
    else {
      // sell or skip
      int take = prices[idx] + help(k, prices, 1, idx + 1, cnt + 1);
      int skip = help(k, prices, 0, idx + 1, cnt);
      profit = max(take, skip);
    }

    return dp[buy][idx][cnt] = profit;
  }

  int maxProfit(int k, vector<int>& prices) {
    memset(dp, -1, sizeof(dp));
    return help(k, prices, 1, 0, 0);
  }
};