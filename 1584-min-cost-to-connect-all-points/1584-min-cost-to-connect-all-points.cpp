class Solution {
public:

	int minCostConnectPoints(vector<vector<int>>& points) {

		int n = points.size();
		int ans = 0;

		priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({0, 0});

		vector<int> firstNode = points[0];

		vector<bool> vis(n);


		while (!pq.empty()) {
			auto it = pq.top();
			int wt = it.first;
			int node = it.second;

			pq.pop();

			if (vis[node]) continue;

			vis[node] = 1;

			ans += wt;

			for (int adjNode = 0; adjNode < n; adjNode++) {
				if (!vis[adjNode]) {
					int adjWt = abs(points[node][0] - points[adjNode][0]) +
					            abs(points[node][1] - points[adjNode][1]);

					pq.push({adjWt, adjNode});
				}
			}
		}

		return ans;
	}
};