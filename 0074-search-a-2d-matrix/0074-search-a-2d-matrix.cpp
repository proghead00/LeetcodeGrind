class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();

        int l = 0, h = r * c - 1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (matrix[mid / c][mid % c] == target) return true;

            else if (matrix[mid / c][mid % c] < target) l++;

            else h--;
        }

        return false;
    }
};