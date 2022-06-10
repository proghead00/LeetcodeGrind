class Solution {
public:
  void help(vector<int> &arr, vector<vector<int>> &ans, int idx) {
    if (idx == arr.size()) {
      ans.push_back(arr);
      return;
    }

    for (int i = idx; i < arr.size(); i++) {
      swap(arr[idx], arr[i]);
      help(arr, ans, idx + 1);
      swap(arr[idx], arr[i]);
    }
  }
  vector<vector<int>> permute(vector<int> &arr) {
    vector<vector<int>> ans;
    help(arr, ans, 0);
    return ans;
  }
};
