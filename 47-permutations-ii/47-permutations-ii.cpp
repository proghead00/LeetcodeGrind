class Solution {
public:
  void help(vector<int> nums, vector<vector<int>> &ans, int idx) {
    if (idx == nums.size() - 1) {
      ans.push_back(nums);
      return;
    }

    for (int i = idx; i < nums.size(); i++) {
      if (i!=idx and nums[i] == nums[idx]) continue;

      swap(nums[idx], nums[i]);
      help(nums, ans, idx + 1);
    }
  }

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    help(nums, ans, 0);
    return ans;
  }
};