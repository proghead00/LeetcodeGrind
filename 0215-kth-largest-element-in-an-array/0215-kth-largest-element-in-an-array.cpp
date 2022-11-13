class Solution {
public:
    int partition(vector<int> &nums, int l, int h) {

        int pivot = nums[h];
        int i = l - 1;

        for (int j = l; j < h; j++) {
            if (nums[j] >= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[i + 1], nums[h]);
        return i + 1;
    }

    int quickSelect(vector<int> &nums, int l, int h, int k) {

        int pv = partition(nums, l, h);

        if (pv + 1 == k) return nums[pv];

        // if (k < pv + 1), it means the number at k is bigger
        // eg: pv + 1 = 4 (4th largest) and k = 2 (2nd largest needed)
        // we know that the larger numbers are on the right half:

        if (k < pv + 1) return quickSelect(nums, l, pv - 1, k);

        else return quickSelect(nums, pv + 1, h, k);
    }


    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, k);
    }

};