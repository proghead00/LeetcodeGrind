#include <bits/stdc++.h>
using namespace std;

void help(vector<int> &arr, int t, vector<int> &temp, int idx,
          vector<vector<int>> &ans) {

  if (!t) {
    ans.push_back(temp);
    return;
  }

  if (idx >= arr.size()) {
    if (!t)
      ans.push_back(temp);
    return;
  }

  if (t < 0)
    return;

  for (int i = idx; i < arr.size(); i++) {
    if (i > idx and arr[i] == arr[i - 1])
      continue;

    if (arr[i] > t)
      break; // ignore all the next elements

    temp.push_back(arr[i]);
    help(arr, t - arr[i], temp, i + 1, ans);

    // after returned:
    temp.pop_back();
  }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target) {
  vector<vector<int>> ans;
  vector<int> temp;
  sort(arr.begin(), arr.end());

  help(arr, target, temp, 0, ans);
  return ans;
}

;
