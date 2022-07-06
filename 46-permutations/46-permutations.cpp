class Solution {
public:
    vector<vector<int>> ans;
    void help(vector<int> &nums, vector<int> &vis, vector<int> &temp) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (vis[i]) continue;

            temp.push_back(nums[i]);
            vis[i] = 1;
            help(nums, vis, temp);

            temp.pop_back();
            vis[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> vis(22, 0);
        vector<int> temp;
        help(nums, vis, temp);
        return ans;
    }
};