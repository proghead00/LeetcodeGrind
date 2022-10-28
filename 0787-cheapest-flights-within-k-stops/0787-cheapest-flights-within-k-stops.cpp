class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		vector<pair<int, int>> gr[n];

		for (auto x : flights) {
			gr[x[0]].push_back({x[1], x[2]});
		}

		queue<pair<int, pair<int, int>>> q;


		q.push({0, {src, 0}}); // { stops, {node, dist } };

		vector<int> dist(n, 1e9);
		dist[src] = 0;

		while (!q.empty()) {

			auto it = q.front();
			q.pop();

			int stops = it.first;
			int node = it.second.first;
			int cost = it.second.second;

			if (stops > k) continue;

			for (auto x : gr[node]) {
				int adjNode = x.first;
				int adjWt = x.second;

				if (cost + adjWt < dist[adjNode] and stops <= k) {
					dist[adjNode] = cost + adjWt;
					q.push({stops + 1, {adjNode, dist[adjNode]}});
				}
			}
		}

		return dist[dst] == 1e9 ? - 1 : dist[dst];
	}
};