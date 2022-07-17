class Solution {
public:
  static bool compare(vector<int> &v1, vector<int> &v2) {
    return v1[1] < v2[1];
  }

  int findMinArrowShots(vector<vector<int>> &points) {

    // sort(points.begin(), points.end(),
    //      [&](vector<int> a, vector<int> b) { return a[1] < b[1]; });

    sort(points.begin(), points.end(), compare);
    int end = points[0][1];
    int ans = 1;

    for (int i = 1; i < points.size(); i++) {
      if (end >= points[i][0])
        continue;

      ans++;
      end = points[i][1];
    }

    return ans;
  }
};