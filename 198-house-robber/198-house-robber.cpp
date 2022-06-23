class Solution {
public:

  int help(vector<int> &nums) {
    int prev1 = nums[0];
    int prev2 = 0;

    for (int i = 1; i < nums.size(); i++) {

      int pick = nums[i];
      if (i >= 2) pick += prev2;

      int ignore = 0 + prev1;

      int curAns = max(pick, ignore);
      prev2 = prev1;
      prev1 = curAns;

    }

    return prev1;
  }

  int rob(vector<int>& nums) {

    int n = nums.size();
    return help(nums);
  }
};