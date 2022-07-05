class Solution {
public:
  void help(vector<int> &nums, vector<vector<int>> &ans, int idx) {
    if (idx == nums.size()) {
      ans.push_back(nums);
      return;
    }
    set<int> s;

    for (int i = idx; i < nums.size(); i++) {
      if (s.find(nums[i]) != s.end()) continue;

      s.insert(nums[i]);
      swap(nums[idx], nums[i]);
      help(nums, ans, idx + 1);
      swap(nums[i], nums[idx]);
    }
  }

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    // sort(nums.begin(), nums.end());
    help(nums, ans, 0);
    return ans;
  }
};