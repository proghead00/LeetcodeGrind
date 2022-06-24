class Solution {
public:
	bool isPossible(vector<int>& target) {
		long sum = 0;
		int mx = 0;

		for (int i = 0; i < target.size(); i++) {
			sum += target[i];
			if (target[mx] < target[i]) mx = i;
		}

		long diff = sum - target[mx];

		if (target[mx] == 1 or diff == 1) return true;

		if ((diff > target[mx]) or (!diff) or (target[mx] % diff == 0)) return false;

		target[mx] %= diff;

		return isPossible(target);
	}
};