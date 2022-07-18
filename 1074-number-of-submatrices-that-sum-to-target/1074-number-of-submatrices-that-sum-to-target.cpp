class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {
      for (int j = 1; j < n; j++) {
        matrix[i][j] += matrix[i][j - 1];
      }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        for (int k = 0; k < m; k++) {
          sum += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
          cnt += mp[sum - target];
          mp[sum]++;
        }
      }
    }

    return cnt;
  }
};
