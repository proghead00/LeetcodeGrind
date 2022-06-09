class Solution {
public:
  void help(int idx, vector<int> &arr, vector<vector<int>> &ans, int target,
            vector<int> &temp) {

    if (idx >= arr.size()) {
      if (!target)
        ans.push_back(temp);
      return;
    }

    if (arr[idx] > target) {
      help(idx + 1, arr, ans, target, temp);
      return;
    }

    if (!target) {
      ans.push_back(temp);
      return;
    }

    // pick multiple times
    temp.push_back(arr[idx]);
    help(idx, arr, ans, target - arr[idx], temp);

    temp.pop_back();
    // don't pick
    help(idx + 1, arr, ans, target, temp);
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    help(0, candidates, ans, target, temp);

    return ans;
  }
};
