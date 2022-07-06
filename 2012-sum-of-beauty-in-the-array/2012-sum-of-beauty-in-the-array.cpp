class Solution {
public:
  int sumOfBeauties(vector<int> &nums) {
    // i POV: min from AND max from left
    vector<int> mnFromRight(nums.size());
    vector<int> mxFromLeft(nums.size());

    int n = nums.size();
    mxFromLeft[0] = nums[0];
    mnFromRight[n - 1] = nums[n - 1];

    for (int i = 1; i < n; i++) {
      mxFromLeft[i] = max(mxFromLeft[i - 1], nums[i]);
    }

    for (int i = nums.size() - 2; i >= 0; i--) {
      mnFromRight[i] = min(mnFromRight[i + 1], nums[i]);
    }
    int sum = 0;

    for (int i = 1; i < n - 1; i++) {
      if (mxFromLeft[i - 1] < nums[i] and nums[i] < mnFromRight[i + 1]) {
        sum += 2;
      } else if (nums[i - 1] < nums[i] and nums[i] < nums[i + 1])
        sum++;
    }
    return sum;
  }
};
