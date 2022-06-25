class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		if (nums.size() <= 2) return true;
		int cnt = 0;

		for (int i = 1; i < nums.size(); i++) {
			if (nums[i - 1] > nums[i]) {
				if (cnt) return false;
                
				cnt++;

				if (i < 2 or nums[i - 2] <= nums[i]) nums[i - 1] = nums[i];
				else nums[i] = nums[i - 1];
			}
		}
		return true;
	}
};