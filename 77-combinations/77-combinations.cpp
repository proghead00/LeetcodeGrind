class Solution {
public:
    void help(vector<int> &nums, int k, int idx, vector<int> &temp, vector<vector<int>> &ans) {
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }


        for (int i = idx; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            help(nums, k, i + 1, temp, ans);
            temp.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) nums[i] = i + 1;

        vector<vector<int>> ans;
        vector<int> temp;

        help(nums, k, 0, temp, ans);
        return ans;
    }
};