class Solution {
public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

		if (grid[0][0] == 1) return -1;

		queue<pair<int, pair<int, int>>> q; // {dist, {x, y}}

		int n = grid.size();

		vector<vector<int>> dist(n, vector<int>(n, 1e9));

		q.push({1, {0, 0}}); // push 1 instead of 0 since we are including that cost (according to question)
		dist[0][0] = 1;

		vector<vector<int>> dd = {
			{ -1, 0}, { -1, 1}, {0, 1}, {1, 1},
			{1, 0}, {1, -1}, {0, -1}, { -1, -1} 
		};

		while (!q.empty()) {

			auto it = q.front();
			q.pop();

			int distFrom = it.first;
			pair<int, int> node = it.second;

			for (int k = 0; k < 8; k++) {
				int x = node.first;
				int y = node.second;

				int xx = x + dd[k][0];
				int yy = y + dd[k][1];

				if (xx >= 0 and xx < n and yy >= 0 and yy < n) {
					if (!grid[xx][yy]) {
						if (distFrom + 1 < dist[xx][yy]) {
							dist[xx][yy] = 1 + distFrom;
							q.push({ 1 + distFrom, {xx, yy} });
						}
					}
				}
			}

		}

		return dist[n - 1][n - 1] == 1e9 ? -1 : dist[n - 1][n - 1];
	}
};