class Solution {
public:
  void help(vector<vector<int>> &ans, vector<int> &nums, int idx,
            vector<int> &temp) {

    ans.push_back(temp);

    for (int i = idx; i < nums.size(); i++) {
      if (i > idx and nums[i] == nums[i - 1])
        continue;

      temp.push_back(nums[i]);
      help(ans, nums, i + 1, temp);

      temp.pop_back();
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> temp;

    sort(nums.begin(), nums.end());
    help(ans, nums, 0, temp);
    return ans;
  }
};
