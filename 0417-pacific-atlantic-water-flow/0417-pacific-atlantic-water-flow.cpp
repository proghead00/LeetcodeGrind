class Solution {
public:

	vector<vector<int>> dd = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};

	void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int x, int y, int r, int c) {

		visited[x][y] = 1;

		for (int k = 0; k < 4; k++) {
			int xx = x + dd[k][0];
			int yy = y + dd[k][1];

			if (xx >= 0 and yy >= 0 and xx < r and yy < c and heights[x][y] <= heights[xx][yy]) {
				if (!visited[xx][yy])
					dfs(heights, visited, xx, yy, r, c);
			}
		}
	}

	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		int r = heights.size();
		int c = heights[0].size();

		vector<vector<int>> pacific(r, vector<int>(c));
		vector<vector<int>> atlantic(r, vector<int>(c));

		// pacific left and atlantic right
		for (int i = 0; i < r; i++) {
			dfs(heights, pacific, i, 0, r, c);
			dfs(heights, atlantic, i, c - 1, r, c);
		}


		// pacific top and atlantic bottom
		for (int i = 0; i < c; i++) {
			dfs(heights, pacific, 0, i, r, c);
			dfs(heights, atlantic, r - 1, i, r, c);
		}

		vector<vector<int>> ans;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++)	{
				if (pacific[i][j] and atlantic[i][j])
					ans.push_back({i, j});
			}
		}

		return ans;
	}
};