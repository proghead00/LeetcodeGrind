class Solution {
public:
  void help(vector<vector<int>> &ans, vector<int> &nums, int idx,
            vector<int> &temp) {

    // we don't return since we need to move till the end of line
      
    // WRONG:
    // if(idx >= nums.size()){
    // ans.push_back(temp);
    //       return;
    // }

    // CORRECT:
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
