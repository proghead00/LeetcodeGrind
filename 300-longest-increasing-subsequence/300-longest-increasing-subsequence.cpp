
class Solution {
public:
  int help(vector<int> &nums, int idx, int prev, vector<vector<int>> &dp) {
    // prev=-1 means that it doesn't have a previous element; that is, the LIS
    // would start from that idx

    if (idx == nums.size())
      return 0;

    if (dp[idx][prev + 1] != -1)
      return dp[idx][prev + 1];

    // int pick
    // if (prev == -1 or nums[idx] > nums[prev])
    //   pick = 1 + help(nums, idx + 1, idx);
    // int nope = 0 + help(nums, idx + 1, prev);

    // return max(nope, pick);

    int len = 0 + help(nums, idx + 1, prev, dp);
    if (prev == -1 or nums[idx] > nums[prev])
      len = max(len, 1 + help(nums, idx + 1, idx, dp));

    return dp[idx][prev + 1] = len;
  }

  int lengthOfLIS(vector<int> &nums) {
    vector<vector<int>> dp(
        nums.size(),
        vector<int>(nums.size() + 1,
                    -1)); // idx changes from 0 to n-1; prev changes from -1
    return help(nums, 0, -1, dp);
  }
};
