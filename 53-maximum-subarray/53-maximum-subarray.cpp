class Solution {
public:
  int maxSubArray(vector<int> &arr) {
    int n = arr.size();
    int s = 0, e = 0;

    long long mx = INT_MIN;
    long long cs = 0;

    for (int i = 0; i < n; i++) {
      cs += arr[i];
      if (cs > mx)
        mx = cs, e = i;
      if (cs <= 0)
        cs = 0, s = i + 1;
    }
    for (int i = s; i <= e; i++)
      cout << arr[i] << " ";
    return mx;
  }
};
