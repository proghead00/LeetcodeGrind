class Solution {
public:

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int vis[101][101];

    bool help(vector<vector<int>> &heights, int mid, int x, int y) {

        if (x == heights.size() - 1 and y == heights[0].size() - 1) return true;

        vis[x][y] = 1;

        for (int k = 0; k < 4; k++) {

            int xx = x + dx[k];
            int yy = y + dy[k];

            if (xx >= 0 and yy >= 0 and xx < heights.size() and yy < heights[0].size()) {

                if (!vis[xx][yy]) {
                    if (abs(heights[xx][yy] - heights[x][y]) <= mid) {

                        if (xx == heights.size() - 1 and yy == heights[0].size() - 1) 
                            return true;

                        if (help(heights, mid, xx, yy)) return true;
                    }
                }
            }
        }

        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int l = 0, h = 1e7;
        int ans = 0;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            memset(vis, 0, sizeof(vis));

            if (help(heights, mid, 0, 0)) {
                ans = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }

        return ans;

    }
};