class Solution {
public:
	int maxScore(vector<int>& cardPoints, int k) {
		int n = cardPoints.size();

		if (k == n) return accumulate(cardPoints.begin(), cardPoints.end(), 0);

		int l = 0, r = cardPoints.size() - k - 1;

		// summing up the part (k elements) outside the window and then sliding the window
		int temp = 0;
		for (int i = r + 1; i < n; i++) temp += cardPoints[i];

		int ans = temp;
		while (r + 1 < n) {
			temp = temp - cardPoints[r + 1] + cardPoints[l];
			ans = max(ans, temp);
			l++; r++;
		}

		return ans;
	}
};