class Solution {
public:
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    int n = boxTypes.size();
    sort(boxTypes.begin(), boxTypes.end(), [](vector<int> &a, vector<int> &b) {
      if (a[1] == b[1])
        return a[0] < b[0];

      return a[1] > b[1];
    });

    int ans = 0;
    for (auto x : boxTypes) {
      if (x[0] > truckSize) {
        ans += truckSize * x[1];
        break;
      }

      ans += x[0] * x[1];
      truckSize = truckSize - x[0];
    }
    return ans;
  }
};
