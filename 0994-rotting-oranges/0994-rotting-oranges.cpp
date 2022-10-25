class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue <pair<int, int>> q;
        int fresh = 0, ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        while (!q.empty()) {
            
            int sz = q.size();
            
            for (int i = 0; i < sz; i++) {
                int x = q.front().first;
                int y = q.front().second;

                q.pop();

                for (int k = 0; k < 4; k++) {
                    int xx = dx[k] + x;
                    int yy = dy[k] + y;

                    if (xx >= 0 and xx < grid.size() and yy >= 0 and yy < grid[0].size()) {

                        if (grid[xx][yy] == 1) {
                            grid[xx][yy] = 2;
                            fresh--;
                            q.push({xx, yy});
                        }
                    }
                }
            }

            if (!q.empty()) ans++;
        }

        return (!fresh) ? ans : -1;
    }
};