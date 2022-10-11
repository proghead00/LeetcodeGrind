class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        // NB: The perimeter of -1 is just an assumption
        int l = 0, h = mat.size() - 1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            // left and right adjacent checks are handled by this
            int idx, mx = 0;
            for (int i = 0; i < mat[0].size(); i++) {
                if (mat[mid][i] > mx) {
                    mx = mat[mid][i];
                    idx = i;
                }
            }

            // handling top and bottom now according to different cases of indices
            if (mid == 0) {
                if (mat[0][idx] > mat[1][idx])
                    return {0, idx};
                else
                    return {1, idx};
            }

            else if (mid == mat.size() - 1) {
                if (mat[mid][idx] > mat[mid - 1][idx])
                    return {mid, idx};
                else
                    return {mid - 1, idx};
            }

            else if (mat[mid][idx] > mat[mid + 1][idx] and mat[mid][idx] > mat[mid - 1][idx])
                return {mid, idx};


            // truncate search space: generic BS
            if (mat[mid][idx] < mat[mid + 1][idx]) l = mid + 1;
            else h = mid - 1;

        }

        return {0, 0};
    }
};