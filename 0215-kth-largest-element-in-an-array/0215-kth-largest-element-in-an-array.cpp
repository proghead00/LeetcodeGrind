class Solution {
public:

	int partition(vector<int> &nums, int l, int r) {    
		int pivot = nums[r];
		int i = l - 1;
		for (int j = l; j < r; j++) {
			if (nums[j] >= pivot) {
				i++;
				swap(nums[i], nums[j]);

			}
		}
		swap(nums[i + 1], nums[r]);
		return i + 1;
	}

	int quickSelect(vector<int> &nums, int l, int r, int k) {

		int p = partition(nums, l, r);

		if (p + 1 == k) // (p + 1)th largest element is found
			return nums[p];

		if (p + 1 > k)
			return quickSelect(nums, l, p - 1, k);

		else
			return quickSelect(nums, p + 1, r, k);

	}

	int findKthLargest(vector<int>& nums, int k) {
		return quickSelect(nums, 0, nums.size() - 1, k);
	}
};