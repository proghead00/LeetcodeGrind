class Solution {
public:

  void subsets(vector<int> &nums, vector<int> temp, vector<vector<int>> &ans, int idx, int n) {

    if (idx == n) {
      ans.push_back(temp);
      return;
    }

    // pick
    temp.push_back(nums[idx]);
    subsets(nums, temp, ans, idx + 1, n);

    // restore to previous state ==> pop_back()
    temp.pop_back();

    // ignore (don't pick)
    subsets(nums, temp, ans, idx + 1, n);

  }


  vector<vector<int>> subsets(vector<int>& nums) {

    vector<vector<int>> ans;
    vector<int> temp;

    subsets(nums, temp, ans, 0, nums.size());
    return ans;
  }
};