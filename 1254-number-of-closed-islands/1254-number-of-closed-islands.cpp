class Solution {
public:

    int changes[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};

    bool valid(vector<vector<int>> &grid, int i, int j, int r, int c) {
        if (i >= 0 and i<r and j >= 0 and j < c and grid[i][j] == 0) return true;
        return false;
    }

    void help(vector<vector<int>> &grid, int i, int j, int r, int c) {

        grid[i][j] = 1; // mark the current cell  as visited

        for (int k = 0; k < 4; k++) {
            int xx = i + changes[k][0];
            int yy = j + changes[k][1];

            if (valid(grid, xx, yy, r, c)) {
                help(grid, xx, yy, r, c);
            }

        }
    }

    int closedIsland(vector<vector<int>>& grid) {

        // convert surroundings (perimeter) to 1 when 0 is found since it won't be a closed island anyway, and neither will the connected islands be closed
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i * j == 0 or i == grid.size() - 1 or j == grid[0].size() - 1) {
                    if (grid[i][j] == 0)
                        help(grid, i, j, grid.size(), grid[0].size());
                }
            }
        }


        // connected components count of the legit closed islands
        int cur = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    help(grid, i, j, grid.size(), grid[0].size());
                    cur++;
                }
            }
        }

        return cur;
    }
};