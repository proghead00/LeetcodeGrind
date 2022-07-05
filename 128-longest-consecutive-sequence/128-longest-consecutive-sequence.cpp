class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int ans = 0;
    // We gotta find the starting point of the consecutive sequence.
    for (int x : nums) {
      // If there exists a number which is one less than x, we don't care, cuz x
      // is not the starting point here
      if (!s.count(x - 1)) {
        // if x is the starting point, we need to find the end point.
        int y = x + 1;
        while (s.count(y))
          y++;
        ans = max(ans, y - x);
      }
    }
    return ans;
  }
};
