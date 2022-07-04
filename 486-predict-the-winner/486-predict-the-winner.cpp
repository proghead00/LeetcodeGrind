class Solution {
public:
  // only calculating score wrt P1
  int help(vector<int> &nums, int l, int r) {
    if (l > r)
      return 0;

    if (l == r)
      return nums[l];

    // when P1 picks up nums[l], he'll try to minimize P2's score
    int curScoreL =
        nums[l] + min(help(nums, l + 2, r), help(nums, l + 1, r - 1));

    int curScoreR =
        nums[r] + min(help(nums, l, r - 2), help(nums, l + 1, r - 1));

    return max(curScoreL, curScoreR);
  }
    
  bool PredictTheWinner(vector<int> &nums) {
    int p1Score = help(nums, 0, nums.size() - 1);

    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
    }

    // sum - p1Score is P2's score, hence P1 can win iff sum - p1Score >= 0
    return p1Score >= sum - p1Score;
  }
};
