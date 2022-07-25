class Solution {
public:
    long long int globalboi = 0;
    long long int temp[1000000];

    void join(vector<int> &nums, int s, int e, int mid) {
        long long int i = s, j = mid + 1;
        long long int k = i;

        while (i <= mid and j <= e) {

            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            }
            else {
                globalboi += mid - i + 1;
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid) temp[k++] = nums[i++];
        while (j <= e) temp[k++] = nums[j++];

        // copy back to nums
        for (long long int k = s; k <= e; k++) nums[k] = temp[k];
    }


    void split(vector<int> &nums, int s, int e) {

        if (s >= e) return;
        int mid = s + (e - s) / 2;

        split(nums, s, mid);
        split(nums, mid + 1, e);

        join(nums, s, e, mid);

    }

    bool isIdealPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return true;

        int localboi = 0;
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] > nums[i + 1]) localboi++;

        split(nums, 0, nums.size() - 1);

        return globalboi == localboi;
    }
};