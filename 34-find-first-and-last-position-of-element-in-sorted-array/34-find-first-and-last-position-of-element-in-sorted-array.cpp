class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int s = 0, e = nums.size() - 1;

        vector<int> ans(2);
        int res = -1;

        // first occurence
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] == target) {
                res = mid;
                e = mid - 1;
            }
            else if (nums[mid] < target) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        if (res == -1) return { -1, -1};
        ans[0] = res;

        // last occurence
        s = 0, e = nums.size() - 1, res = -1;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (nums[mid] == target) {
                res = mid;
                s = mid + 1;
            }
            else if (nums[mid] < target) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        ans[1] = res;

        return ans;

    }
};