class Solution {
public:
  int kadane(vector<int> &a, vector<int> &b) {
    int currentSum = 0, mx = 0;
    int sum = accumulate(a.begin(), a.end(), 0);

    for (int i = 0; i < a.size(); i++) {
      currentSum += b[i] - a[i];
      if (currentSum < 0)
        currentSum = 0;
        
      mx = max(mx, currentSum);
    }
    return sum + mx;
  }

  int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2) {
    return max(kadane(nums1, nums2), kadane(nums2, nums1));
  }
};
