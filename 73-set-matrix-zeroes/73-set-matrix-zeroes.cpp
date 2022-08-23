class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r1 = 1, c1 = 1;
        // edge case
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0)
                r1 = 0;
        }

        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[0][j] == 0)
                c1 = 0;
        }

        for (int i = 1; i < matrix.size(); i++) {
            for (int  j = 1; j < matrix[0].size(); j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = 0, matrix[0][j] = 0;
        }

        // now replace

        // individually go thru row and col markers
        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < matrix[0].size(); j++)
                    matrix[i][j] = 0;
            }
        }

        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < matrix.size(); i++)
                    matrix[i][j] = 0;
            }
        }

        // edge cases
        for (int j = 0; j < matrix[0].size(); j++) {
            if (c1 == 0) matrix[0][j] = 0;
        }
        for (int i = 0; i < matrix.size(); i++) {
            if (r1 == 0) matrix[i][0] = 0;
        }

    }
};