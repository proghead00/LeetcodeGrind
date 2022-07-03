class Solution {
public:
  bool help(vector<int> &nums, int p, int scoreA, int scoreB, int l, int r) {
    if (l > r)
      return scoreA >= scoreB;

    if (p == 1)
      return help(nums, 2, scoreA + nums[l], scoreB, l + 1, r) or
             help(nums, 2, scoreA + nums[r], scoreB, l, r - 1);
    else
      return help(nums, 1, scoreA, scoreB + nums[l], l + 1, r) and
             help(nums, 1, scoreA, scoreB + nums[r], l, r - 1);
  }

  bool PredictTheWinner(vector<int> &nums) {
    return help(nums, 1, 0, 0, 0, nums.size() - 1);
  }
};
