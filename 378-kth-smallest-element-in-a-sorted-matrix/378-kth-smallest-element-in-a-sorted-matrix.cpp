class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[n - 1][m - 1];

        while (low < high) {
            int cnt = 0;
            int mid = low + (high - low) / 2;

            // check for number of elements less than mid in each row
            for (int i = 0; i < n; i++) {
                cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }

            if (cnt < k) low = mid + 1;
            else if (cnt >= k) high = mid;
        }
        return low;
    }
};