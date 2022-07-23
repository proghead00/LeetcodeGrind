class Solution {
public:
    vector<int> temp;

    void join(int low, int high, int mid, vector<int> &nums) {

        int i = low, j = mid + 1;
        int k = 0;

        while (i <= mid and j <= high) {
            if (nums[i] < nums[j]) temp[k++] = nums[i++];
            else temp[k++] = nums[j++];
        }

        while (i <= mid) temp[k++] = nums[i++];
        while (j <= high) temp[k++] = nums[j++];

        // put the elements together
        for (int kk = low; kk <= high; kk++)
            nums[kk] = temp[kk - low];

    }

    void splitRecur(int low, int high, vector<int> &nums) {
        if (low >= high) return;

        int mid = (low + high) / 2;

        splitRecur(low, mid, nums);
        splitRecur(mid + 1, high, nums);

        join(low, high, mid, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        temp.resize(nums.size());

        splitRecur(low, high, nums);

        return nums;
    }
};