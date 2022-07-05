class Solution {
public:
    void help(vector<int> &nums, vector<vector<int>> &ans, int idx) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        vector<int> vis(21, 0);

        for (int i = idx; i < nums.size(); i++) {
            if (vis[nums[i] + 10] == 1)
                continue;

            vis[nums[i] + 10] = 1;

            swap(nums[idx], nums[i]);
            help(nums, ans, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        help(nums, ans, 0);
        return ans;
    }
};