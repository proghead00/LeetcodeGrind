class Solution {
public:
  int maxProfit(vector<int>& prices) {

    int profit = 0;

    // buy at local minima, sell at maxima

    for (int i = 1; i < prices.size(); i++) {
      // sell when there's a maxima:
      if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
    }

    return profit;
  }
};