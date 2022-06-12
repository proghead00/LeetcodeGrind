class Solution {
public:
  int minOperations(vector<int> &nums, int x) {
    int sum = 0, e = nums.size() - 1;
    for (int i = 0; i < nums.size(); i++)
      sum += nums[i];

    // we need subarray of value (s-x)
    int target = sum - x;

    int cs = 0, mx = 0;

    // starting idx of subarray: s
    int s = 0;
    int f = 0;

    for (int i = 0; i < nums.size(); i++) {
      cs += nums[i];

      // shrink the window
      while (s <= i and cs > target) {
        cs -= nums[s];
        s++;
      }

      if (cs == target) {
        f = 1;
        mx = max(mx, i - s + 1);
      }
    }

    return (!f) ? -1 : nums.size() - mx;
  }
};
