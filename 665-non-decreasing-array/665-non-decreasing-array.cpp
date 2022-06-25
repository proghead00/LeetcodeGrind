class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		if (nums.size() <= 2) return true;
		bool changed = false;

		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i] <= nums[i + 1]) continue;
			// used continue, hence we only have nums[i] > nums[i+1]

			if (changed) return false; // cannot mutate any further (since, atmost one)

			// try to decrease (i-1)th element when standing at i
			// 	▶ since we don't know what's ahead of ith element yet, and it'd be better if we have smaller element on ith, so that there can be greater elements on the right without any conflict

			//	  i  i+1
			// 2  5  4
			if (!i or nums[i + 1] >= nums[i - 1])
				nums[i] = nums[i + 1];

			//	  i  i+1
			// 3  5  2
			else nums[i + 1] = nums[i];

			changed = true;
		}

		return true;
	}
};